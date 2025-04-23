/*
This problem was asked by Stripe.

Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
*/

#include <bits/stdc++.h>
using namespace std;

int consecutiveRun(int n)
{

    int count = 0;
    int maxCount = 0;

    while (n > 0)
    {
        if (n & 1)
        {
            count++;
            maxCount = max(count, maxCount);
        }
        else
        {
            count = 0;
        }
        n >>= 1;
    }
    return maxCount;
}

int main()
{
    int n = 156;

    cout << "Length of the longest consecutive run of 1s: " << consecutiveRun(n);
    return 0;
}