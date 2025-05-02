/*
This problem was asked by Facebook.

Given an array of numbers of length N, find both the minimum and maximum using less than 2 * (N - 2) comparisons.
*/

#include <bits./stdc++.h>
using namespace std;

// Comparisons when n is ODD : 3 * (n - 1) / 2
// Comparisons when n is EVEN : 1 + 3 * (n - 2) / 2
// We are doing three comparisons for every two element instead if we have used linear search we would have done 2 coparisons for evey element to get min or max.
pair<int, int> findMinMax(vector<int> &arr, int n)
{
    pair<int, int> p;
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    int i = 0;

    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            maxNum = arr[0];
            minNum = arr[1];
        }
        else
        {
            maxNum = arr[1];
            minNum = arr[0];
        }
        i = 2;
    }
    else
    {

        maxNum = arr[0];
        minNum = arr[1];
        i = 1;
    }

    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > maxNum)
                maxNum = arr[i];
            if (arr[i + 1] < minNum)
                minNum = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > maxNum)
                maxNum = arr[i + 1];
            if (arr[i] < minNum)
                minNum = arr[i];
        }
        i += 2;
    }
    p.first = minNum;
    p.second = maxNum;
    return p;
}

int main()
{
    vector<int> arr = {3, 5, 1, 8, 2, 7, 4, 6};
    int n = arr.size();
    pair<int, int> result = findMinMax(arr, n);
    cout << "Minimum: " << result.first << ", Maximum: " << result.second << endl;
    return 0;
}
