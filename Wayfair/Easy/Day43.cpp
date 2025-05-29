/*
This problem was asked by Wayfair.

You are given a 2 x N board, and instructed to completely cover the board with the following shapes:

Dominoes, or 2 x 1 rectangles.
Trominoes, or L-shapes.

For example, if N = 4, here is one possible configuration, where A is a domino, and B and C are trominoes.

A B B C
A B C C
Given an integer N, determine in how many ways this task is possible.
*/

#include <iostream>
#include <vector>
using namespace std;

int numTilings(int n)
{
    int MOD = 1e9 + 7;

    if (n <= 2)
        return n;

    // Start from 3rd
    long current = 5;
    long prev = 2;
    long prevPrev = 1;

    // Formula : 2 * f(n - 1) + f(n - 3)

    for (int i = 4; i <= n; i++)
    {
        long t = prev;
        prev = current;
        current = (2 * prev % MOD + prevPrev % MOD) % MOD;
        prevPrev = t;
    }

    return (int)current;
}

int main()
{
    int N = 10;
    cout << "Number of tilings: " << numTilings(N) << endl;
    return 0;
}