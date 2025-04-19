/*
This problem was asked by Google.

Let A be an N by M matrix in which every row and every column is sorted.

Given i1, j1, i2, and j2, compute the number of elements of M smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]
And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15 numbers in the matrix smaller than 6 or greater than 23.
*/

#include <bits/stdc++.h>
using namespace std;

int countElements(vector<vector<int>> &matrix, int i1, int j1, int i2, int j2)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;

    int x = matrix[i1][j1];
    int y = matrix[i2][j2];

    // Counting Till i1,j1
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] >= x)
        {
            break;
        }
        count++;

        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] >= x)
            {
                break;
            }
            count++;
        }
    }
    // Counting Till i2,j2
    for (int i = n - 1; i >= 0; i--)
    {
        if (matrix[i][m - 1] <= y)
        {
            break;
        }

        count++;

        for (int j = m - 2; j >= 0; j--)
        {
            if (matrix[i][j] <= y)
            {
                break;
            }
            count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 7, 10, 15, 20},
        {2, 6, 9, 14, 22, 25},
        {3, 8, 10, 15, 25, 30},
        {10, 11, 12, 23, 30, 35},
        {20, 25, 30, 35, 40, 45}};
    int i1 = 1, j1 = 1;
    int i2 = 3, j2 = 3;
    cout << countElements(matrix, i1, j1, i2, j2) << endl;
    return 0;
}
