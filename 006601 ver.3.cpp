#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

class Display;

class Chess_Board
{
public:
    friend class Display;

    void Display_Chess_board(int choice_number)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << endl << endl;
        wchar_t chess_Pieces[16][16] = {};

        if (choice_number == 0)
        {
            wchar_t chessPieces[16][16] =
            {
                {L' ', L' ', L' ', L' ', L' ', L' ', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'},
                {L' ', L' ', L' ', L' ', L' ', L'1', L'♖', L'♘', L'♗', L'♕', L'♔', L'♗', L'♘', L'♖', L'1'},
                {L' ', L' ', L' ', L' ', L' ', L'2', L'♙', L'♙', L'♙', L'♙', L'♙', L'♙', L'♙', L'♙', L'2'},
                {L' ', L' ', L' ', L' ', L' ', L'3', L'■', L'□', L'■', L'□', L'■', L'□', L'■', L'□', L'3'},
                {L' ', L' ', L' ', L' ', L' ', L'4', L'□', L'■', L'□', L'■', L'□',L'■', L'□', L'■', L'4'},
                {L' ', L' ', L' ', L' ', L' ', L'5', L'■', L'□', L'■', L'□', L'■', L'□', L'■', L'□', L'5'},
                {L' ', L' ', L' ', L' ', L' ', L'6', L'□', L'■', L'□', L'■', L'□', L'■', L'□', L'■', L'6'},
                {L' ', L' ', L' ', L' ', L' ', L'7', L'♟', L'♟', L'♟', L'♟', L'♟', L'♟', L'♟', L'♟', L'7'},
                {L' ', L' ', L' ', L' ', L' ', L'8', L'♜', L'♞', L'♝', L'♛', L'♚', L'♝', L'♞', L'♜', L'8'},
                {L' ', L' ', L' ', L' ', L' ', L' ', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'}
            };

            for (int row = 0; row < 16; row++)
            {
                for (int col = 0; col < 16; col++)
                {
                    wcout << chessPieces[row][col] << L' ';
                }
                wcout << endl;
            }
        }


        if (choice_number == 1)
        {

            wchar_t chessPieces[16][16] =
            {
                {L' ', L' ', L' ', L' ', L' ', L' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
                {L' ', L' ', L' ', L' ', L' ', L'8', L'♜', L'♞', L'♝', L'♛', L'♚', L'♝', L'♞', L'♜', L'8'},
                {L' ', L' ', L' ', L' ', L' ', L'7', L'♟', L'♟', L'♟', L'♟', L'♟', L'♟', L'♟', L'♟', L'7'},
                {L' ', L' ', L' ', L' ', L' ', L'6', L'■', L'□', L'■', L'□', L'■', L'□', L'■', L'□', L'6'},
                {L' ', L' ', L' ', L' ', L' ', L'5', L'□', L'■', L'□', L'■', L'□',L'■', L'□', L'■', L'5'},
                {L' ', L' ', L' ', L' ', L' ', L'4', L'■', L'□', L'■', L'□', L'■', L'□', L'■', L'□', L'4'},
                {L' ', L' ', L' ', L' ', L' ', L'3', L'□', L'■', L'□', L'■', L'□', L'■', L'□', L'■', L'3'},
                {L' ', L' ', L' ', L' ', L' ', L'2', L'♙', L'♙', L'♙', L'♙', L'♙', L'♙', L'♙', L'♙', L'2'},
                {L' ', L' ', L' ', L' ', L' ', L'1', L'♖', L'♘', L'♗', L'♕', L'♔', L'♗', L'♘', L'♖', L'1'},
                {L' ', L' ', L' ', L' ', L' ', L' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}
            };



            for (int row = 0; row < 16; row++)
            {
                for (int col = 0; col < 16; col++)
                {
                    wcout << chessPieces[row][col] << L' ';
                }
                wcout << endl;
            }
        }
    }
};

class Display
{
public:
    void Display_Chess_board(Chess_Board& chess_Board, int choice_number)
    {
        if (choice_number == 1)
        {
            cout << endl << "Відображення доски від гравця білими шахами" << endl;
            chess_Board.Display_Chess_board(choice_number);
        }
        if (choice_number == 0)
        {
            cout << endl << "Відображення доски від гравця чорними шахами: " << endl;
            chess_Board.Display_Chess_board(choice_number);
        }
        if (choice_number != 0 && choice_number != 1)
        {
            cout << endl << "Помилка, введене вами число невірне, шахова доска не буде відображена." << endl;
        }

    }
};

int main()
{
    system("chcp 1251 > nul");
    int choice_number;

    cout << "Ця програма відображає положення шахової доски в залежності від вибору користувача." << endl << endl;
    cout << "Введіть 0, якщо бажаєте побачити положення шахової доски від гравця чорними шахами, або 1, якщо білими: ";
    cin >> choice_number;

    Chess_Board chess_Board;
    Display display;
    display.Display_Chess_board(chess_Board, choice_number);
    return 0;
}