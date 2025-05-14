/*
This problem was asked by Facebook.

On a mysterious island there are creatures known as Quxes which come in three colors: red, green, and blue. One power of the Qux is that if two of them are standing next to each other, they can transform into a single creature of the third color.

Given N Quxes standing in a line, determine the smallest number of them remaining after any possible sequence of such transformations.

For example, given the input ['R', 'G', 'B', 'G', 'B'], it is possible to end up with a single Qux through the following steps:

        Arrangement       |   Change
----------------------------------------
['R', 'G', 'B', 'G', 'B'] | (R, G) -> B
['B', 'B', 'G', 'B']      | (B, G) -> R
['B', 'R', 'B']           | (R, B) -> G
['B', 'G']                | (B, G) -> R
['R']                     |

*/

#include <bits/stdc++.h>
using namespace std;

int min_remaining_quxes(vector<char> quxes)
{
    int n = quxes.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Count the occurrences of each color
    int countR = 0, countG = 0, countB = 0;
    for (char c : quxes)
    {
        if (c == 'R')
            countR++;
        else if (c == 'G')
            countG++;
        else if (c == 'B')
            countB++;
    }

    if (countR == n || countG == n || countB == n)
        return 1;

    if (countR % 2 == countG % 2 and countG % 2 == countB % 2)
        return 2;

    return 1;
}

int main()
{
    vector<char> quxes = {'R', 'G', 'B', 'G', 'B'};
    cout << "Initial Quxes: ";
    for (char c : quxes)
    {
        cout << c << " ";
    }
    cout << endl;

    int result = min_remaining_quxes(quxes);
    cout << "Minimum remaining Quxes: " << result << endl;

    return 0;
}