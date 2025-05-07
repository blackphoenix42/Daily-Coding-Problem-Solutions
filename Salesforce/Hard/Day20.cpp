/*
This problem was asked by Salesforce.

Connect 4 is a game where opponents take turns dropping red or black discs into a 7 x 6 vertically suspended grid. The game ends either when one player creates a line of four consecutive discs of their color (horizontally, vertically, or diagonally), or when there are no more spots left in the grid.

Design and implement Connect 4.

*/
#include <bits/stdc++.h>
using namespace std;

class Connect4
{
private:
    vector<vector<char>> grid;
    const int rows = 7;
    const int cols = 6;
    char currentPlayer;

public:
    Connect4()
    {
        grid.resize(rows, vector<char>(cols, ' '));
        currentPlayer = 'R';
    }

    // Function to drop a disc into the grid
    bool dropDisc(int col, char player)
    {
        if (col < 0 || col >= cols || player != 'R' && player != 'B')
            return false;

        for (int row = rows - 1; row >= 0; --row)
        {
            if (grid[row][col] == ' ')
            {
                grid[row][col] = player;
                currentPlayer = (currentPlayer == 'R') ? 'B' : 'R'; // Switch players
                return true;
            }
        }
        return false; // Column is full
    }

    // Function to check for a win
    bool checkWin(char player)
    {
        // Check horizontal, vertical and diagonal lines for a win
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (grid[row][col] == player)
                {
                    if (checkDirection(row, col, 1, 0, player) || // Horizontal
                        checkDirection(row, col, 0, 1, player) || // Vertical
                        checkDirection(row, col, 1, 1, player) || // Diagonal down-right
                        checkDirection(row, col, 1, -1, player))  // Diagonal down-left
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // Function to check for a draw
    bool isDraw()
    {
        for (int col = 0; col < cols; ++col)
        {
            if (grid[0][col] == ' ')
                return false;
        }
        return true;
    }

    // Function to check a specific direction for a win
    bool checkDirection(int row, int col, int deltaRow, int deltaCol, char player)
    {
        int count = 0;
        for (int i = 0; i < 4; ++i)
        {
            int newRow = row + i * deltaRow;
            int newCol = col + i * deltaCol;
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != player)
                return false;
            count++;
        }
        return count == 4;
    }

    // Function to print the grid (for debugging purposes)
    void printGrid()
    {
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                cout << grid[row][col] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Connect4 *game = new Connect4();

    game->dropDisc(0, 'R');
    game->dropDisc(1, 'B');
    game->dropDisc(0, 'R');
    game->dropDisc(1, 'B');
    game->dropDisc(0, 'R');
    game->dropDisc(1, 'B');
    game->dropDisc(0, 'R');
    game->printGrid();

    if (game->checkWin('R'))
    {
        cout << "Player R wins!" << endl;
    }
    else if (game->checkWin('B'))
    {
        cout << "Player B wins!" << endl;
    }
    else if (game->isDraw())
    {
        cout << "It's a draw!" << endl;
    }
    else
    {
        cout << "Game is still ongoing." << endl;
    }

    return 0;
}