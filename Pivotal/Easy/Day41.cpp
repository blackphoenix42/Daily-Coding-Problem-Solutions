/*

This problem was asked by Pivotal.

Write an algorithm that finds the total number of set bits in all integers between 1 and N.

*/

#include <bits/stdc++.h>
using namespace std;

int getBits(int n)
{
    int i = 1;
    int cnt = 0;
    while (i <= n)
    {
        int k = i;
        while (k != 0)
        {
            cnt++;
            k = k & (k - 1);
        }
        i++;
    }
    return cnt;
}

int main()
{
    int n = 13;
    cout << " Total Bits : " << getBits(n);
}