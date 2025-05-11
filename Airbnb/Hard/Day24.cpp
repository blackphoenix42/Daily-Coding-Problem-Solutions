/*
This problem was asked by Airbnb.

An 8-puzzle is a game played on a 3 x 3 board of tiles, with the ninth tile missing. The remaining tiles are labeled 1 through 8 but shuffled randomly. Tiles may slide horizontally or vertically into an empty space, but may not be removed from the board.

Design a class to represent the board, and find a series of steps to bring the board to the state [[1, 2, 3], [4, 5, 6], [7, 8, None]].
*/

#include <bits/stdc++.h>
using namespace std;

// The time complexity of the solve function is O(4^(n*m)) because in the worst case, we can have 4 possible moves (up, down, left, right) for each tile on the board.
// Since the board is 3x3, we have 9 tiles, and each tile can lead to 4 possible moves.
// This results in a branching factor of 4 for each tile, leading to an exponential growth of the search space.

// The space complexity is O(n*m) because we need to store the visited states in a set and the queue used for BFS.
// The visited set stores the unique configurations of the board, and since there are n*m tiles, the maximum number of unique configurations is n*m.
// The queue stores the states to be explored, and in the worst case, it can also grow to O(n*m) in size.

class PuzzleBoard
{
private:
    vector<vector<int>> board;
    pair<int, int> emptyTile; // Position of the empty tile (None)

    // Directions for moving the empty tile: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValidMove(int x, int y)
    {
        return x >= 0 && x < 3 && y >= 0 && y < 3;
    }

public:
    PuzzleBoard(vector<vector<int>> initialBoard) : board(initialBoard)
    {
        // Find the position of the empty tile
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == 0)
                {
                    emptyTile = {i, j};
                    return;
                }
            }
        }
    }

    vector<vector<int>> getBoard()
    {
        return board;
    }

    bool isSolvable()
    {
        int inversions = 0;
        vector<int> flatBoard;

        // Flatten the board and count inversions
        for (const auto &row : board)
        {
            for (const auto &tile : row)
            {
                if (tile != 0)
                {
                    flatBoard.push_back(tile);
                }
            }
        }

        for (size_t i = 0; i < flatBoard.size(); ++i)
        {
            for (size_t j = i + 1; j < flatBoard.size(); ++j)
            {
                if (flatBoard[i] > flatBoard[j])
                {
                    ++inversions;
                }
            }
        }

        return inversions % 2 == 0;
    }

    vector<string> solve()
    {
        if (!isSolvable())
        {
            return {};
        }

        // BFS to find the solution
        queue<pair<vector<vector<int>>, vector<string>>> q;
        set<vector<vector<int>>> visited;
        q.push({board, {}});
        visited.insert(board);

        while (!q.empty())
        {
            auto [currentBoard, path] = q.front();
            q.pop();

            if (currentBoard == vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}})
            {
                return path;
            }

            // Find the empty tile position
            pair<int, int> empty;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (currentBoard[i][j] == 0)
                    {
                        empty = {i, j};
                        break;
                    }
                }
            }

            // Try all possible moves
            for (auto [dx, dy] : directions)
            {
                int newX = empty.first + dx;
                int newY = empty.second + dy;

                if (isValidMove(newX, newY))
                {
                    auto newBoard = currentBoard;
                    swap(newBoard[empty.first][empty.second], newBoard[newX][newY]);

                    if (visited.find(newBoard) == visited.end())
                    {
                        visited.insert(newBoard);
                        vector<string> newPath = path;

                        if (dx == -1 && dy == 0)
                            newPath.push_back("Up");
                        else if (dx == 1 && dy == 0)
                            newPath.push_back("Down");
                        else if (dx == 0 && dy == -1)
                            newPath.push_back("Left");
                        else if (dx == 0 && dy == 1)
                            newPath.push_back("Right");

                        q.push({newBoard, newPath});
                    }
                }
            }
        }

        return {};
    }

    vector<vector<int>> getFinalBoardState(const vector<string> &steps)
    {
        auto finalBoard = board;
        pair<int, int> empty = emptyTile;

        for (const auto &step : steps)
        {
            int dx = 0, dy = 0;
            if (step == "Up")
                dx = -1;
            else if (step == "Down")
                dx = 1;
            else if (step == "Left")
                dy = -1;
            else if (step == "Right")
                dy = 1;

            int newX = empty.first + dx;
            int newY = empty.second + dy;

            if (isValidMove(newX, newY))
            {
                swap(finalBoard[empty.first][empty.second], finalBoard[newX][newY]);
                empty = {newX, newY};
            }
        }

        return finalBoard;
    }

    void printBoard(const vector<vector<int>> &finalBoard = {})
    {
        auto boardToPrint = finalBoard.empty() ? board : finalBoard;
        for (const auto &row : boardToPrint)
        {
            for (const auto &tile : row)
            {
                cout << (tile == 0 ? "None" : to_string(tile)) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // vector<vector<int>> initialBoard = {
    //     {1, 2, 3},
    //     {4, 0, 6},
    //     {7, 5, 8}};

    // Not Solvable
    // vector<vector<int>> initialBoard = {
    //     {8, 1, 2},
    //     {0, 4, 3},
    //     {7, 6, 5}};

    vector<vector<int>> initialBoard = {
        {1, 8, 2},
        {0, 4, 3},
        {7, 6, 5}};

    PuzzleBoard puzzle(initialBoard);
    cout << "Initial board state:" << endl;
    puzzle.printBoard();

    vector<string> solution = puzzle.solve();

    if (solution.empty())
    {
        cout << "No solution found." << endl;
    }
    else
    {
        cout << "Solution steps:" << endl;
        for (const auto &step : solution)
        {
            cout << step << endl;
        }

        auto finalBoard = puzzle.getFinalBoardState(solution);
        cout << "Final board state:" << endl;
        puzzle.printBoard(finalBoard);
    }

    return 0;
}