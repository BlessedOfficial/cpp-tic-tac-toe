#include <iostream>
using namespace std;

// global variables
char board[3][3] =
    {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}};
char currentPlayer = 'A';
char currentMarker;
char p1;
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
    bool gameOver = false;
    bool validSelection = false;
    cout << "--------------Tic Tac Toe Game--------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "===Player A===" << endl;
    cout << endl;
    cout << "Select your marker X or O" << endl;
    cin >> p1;

    // Start Game
    while (true)
    {
        cout << "Turn no.: " << turnsCount << endl;
        cout << "Player: " << currentPlayer << endl;

        promptMove();
        drawBoard();

        if (checkHasWon())
        {
            cout << "Player " << currentPlayer << " won!!" << endl;
            break;
        }

        currentPlayerManager();
        turnsCount++;
    }

    drawBoard();

    gameOver = checkHasWon();
    if (gameOver)
    {
        cout << "Logic Error";
    }

    while (true)
    {
        cout << "\nPlayer " << currentPlayer
             << " (" << currentMarker << ")\n";

        promptMove();
        drawBoard();

        if (checkHasWon())
        {
            cout << "Player " << currentPlayer << " won!\n";
            break;
        }

        turnsCount++;

        if (turnsCount == 9)
        {
            cout << "It's a draw!\n";
            break;
        }

        currentPlayerManager();
    }

    cout << "Player " << currentPlayer << " won!!" << endl;
}

int main()
{

    game();
    return 0;
}