/*
This problem was asked by Slack.

You are given an N by M matrix of 0s and 1s. Starting from the top left corner, how many ways are there to reach the bottom right corner?

You can only move right and down. 0 represents an empty space while 1 represents a wall you cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]
Return two, as there are only two ways to get to the bottom right:

Right, down, down, right
Down, right, down, right
The top left corner and bottom right corner will always be 0.

*/

#include <bits/stdc++.h>
using namespace std;

void bfs(int &res, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int rows, int cols, int dirs[2][2])
{
    if (i == rows - 1 and j == cols - 1)
    {
        res++;
        return;
    }

    visited[i][j] = true;

    for (int k = 0; k < 2; k++)
    {
        int newI = i + dirs[k][0];
        int newJ = j + dirs[k][1];

        if (newI < 0 or newI >= rows or newJ < 0 or newJ >= cols)
            continue;

        if (matrix[newI][newJ] == 1 or visited[newI][newJ])
            continue;

        bfs(res, matrix, visited, newI, newJ, rows, cols, dirs);
    }

    visited[i][j] = false;
}

int countPaths(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    if (matrix[0][0] == 1 || matrix[rows - 1][cols - 1] == 1)
        return 0;

    int res = 0;

    int dirs[2][2] = {
        {1, 0},
        {0, 1},
    };

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    bfs(res, matrix, visited, 0, 0, rows, cols, dirs);

    return res;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 0, 0}};

    cout << "Total Paths : " << countPaths(matrix) << endl;
    return 0;
}