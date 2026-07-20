#include <iostream>
using namespace std;

// global variables
char board[3][3] =
    {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}};
char currentPlayer = 'A';
char currentMarker = 'X';
char p1 = 'X';
int turnsCount = 0;

// implementation functions
void drawBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void resetBoard()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            board[row][col] = '.';
        }
    }
}

bool checkHasWon()
{
    if (
        // Rows
        (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '.') ||
        (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '.') ||
        (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '.') ||

        // Columns
        (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '.') ||
        (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '.') ||
        (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '.') ||

        // Diagonals
        (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.'))
        return true;

    else
        return false;
}

void promptMove()
{
    int row, col;

    while (true)
    {
        cout << "Row (0-2): ";
        cin >> row;

        cout << "Column (0-2): ";
        cin >> col;

        if (row >= 0 && row < 3 &&
            col >= 0 && col < 3 &&
            board[row][col] == '.')
        {
            board[row][col] = currentMarker;
            break;
        }

        cout << "Invalid move. Try again.\n";
    }
}

void currentPlayerManager()
{

    if (currentPlayer == 'A')
    {
        currentPlayer = 'B';
    }
    else
    {
        currentPlayer = 'A';
    }

    if (currentMarker == 'X')
    {
        currentMarker = 'O';
    }
    else
    {
        currentMarker = 'X';
    }
}

void game()
{
    char playAgain;
    while (true)
    {
        resetBoard();
        turnsCount = 0;

        bool gameOver = false;
        bool validSelection = false;
        cout << "--------------Tic Tac Toe Game--------------" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "===Player A===" << endl;
        cout << endl;
        cout << "Select your marker X or O" << endl;
        cin >> p1;

        if (p1 == 'X' || p1 == 'x')
        {
            currentPlayer = 'A';
            currentMarker = 'X';
        }
        else if (p1 == 'O' || p1 == 'o')
        {
            currentPlayer = 'A';
            currentMarker = 'O';
        }
        else
        {
            cout << "Invalid marker.\n";
            cout << "Default marker: X is going to be your marker!. \n";

            currentPlayer = 'A';
            currentMarker = 'X';
        }

        // Start Game

        while (true)
        {
            cout << "\nPlayer " << currentPlayer
                 << " (" << currentMarker << ")\n";

            
            drawBoard();
            promptMove();
            turnsCount++;
            drawBoard();

            if (checkHasWon())
            {
                cout << "Player " << currentPlayer << " won!\n";
                break;
            }

            if (turnsCount == 9)
            {
                cout << "It's a draw!\n";
                break;
            }

            currentPlayerManager();
        }

        cout << "Do you want to play again? " << endl;
        cin >> playAgain;
        if (playAgain == 'N' || playAgain == 'n')
        {
            break;
        }
    }
}

int main()
{

    game();
    return 0;
}