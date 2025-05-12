/*
This problem was asked by Yelp.

You are given an array of integers, where each element represents the maximum number of steps that can be jumped going forward from that element. Write a function to return the minimum number of jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
*/

#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return 0;

    int jumps = 0;
    int currEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; i++)
    {
        farthest = max(farthest, i + arr[i]);
        if (i == currEnd)
        {
            jumps++;
            currEnd = farthest;
            if (currEnd >= n - 1)
                break;
        }
    }
    return jumps;
}

int main()
{
    vector<int> arr = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
    cout << minJumps(arr) << endl;
    return 0;
}