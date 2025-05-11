#include <iostream>
using namespace std;

const int X = 1, O = -1, EMPTY = 0;
int board[3][3];
int currPlayer;

void clearBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
    currPlayer = X;
}

void putMark(int i, int j)
{
    board[i][j] = currPlayer;
    currPlayer = -currPlayer;
}

bool isWin(int mark)
{
    int win = 3 * mark;

    // row and column check
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] + board[i][1] + board[i][2] == win)
            return true;
        if (board[0][i] + board[1][i] + board[2][i] == win)
            return true;
    }

    // diagonals check
    if (board[0][0] + board[1][1] + board[2][2] == win)
        return true;
    if (board[2][0] + board[1][1] + board[0][2] == win)
        return true;

    return false;
}

int getWinner()
{
    if (isWin(X))
        return X;
    if (isWin(O))
        return O;
    return EMPTY;
}

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (board[i][j])
            {
            case X:
                cout << "X";
                break;
            case O:
                cout << "O";
                break;
            case EMPTY:
                cout << " ";
                break;
            }
            if (j < 2)
                cout << "|";
        }
        if (i < 2)
            cout << "\n-+-+-\n";
    }
    cout << endl;
}

int main()
{
    clearBoard();
    // printBoard();
    putMark(0, 0);
    putMark(1, 1);
    putMark(0, 1);
    putMark(0, 2);
    putMark(2, 0);
    putMark(1, 2);
    putMark(2, 2);
    putMark(2, 1);
    putMark(1, 0);
    printBoard();
    int winner = getWinner();
    if (winner != EMPTY)
        cout << " " << (winner == X ? "X" : "O") << " wins" << endl;
    else
        cout << " Tie" << endl;
    
    return EXIT_SUCCESS;
}