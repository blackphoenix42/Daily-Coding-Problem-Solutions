/*
This problem was asked by LinkedIn.

You are given a string consisting of the letters x and y, such as xyxxxyxyy. In addition, you have an operation called flip, which changes a single x to y or vice versa.

Determine how many times you would need to apply this operation to ensure that all x's come before all y's. In the preceding example, it suffices to flip the second and sixth characters, so you should return 2.

*/

#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoXY(string s)
{
    int totalX = 0;

    for (char ch : s)
        if (ch == 'x')
            totalX++;

    int flipY = 0, flipX = totalX;

    int minFlips = INT_MAX;

    for (char ch : s)
    {
        minFlips = min(minFlips, flipX + flipY);
        if (ch == 'y')
        {
            flipY++;
        }
        else
        {
            flipX--;
        }
    }

    minFlips = min(minFlips, flipX + flipY);

    return minFlips;
}

int main()
{
    string input = "xyxxxyxyy"; // 🔧 Change this to test other inputs

    int result = minFlipsMonoXY(input);

    cout << "Input string: " << input << endl;
    cout << "Minimum flips required: " << result << endl;

    return 0;
}