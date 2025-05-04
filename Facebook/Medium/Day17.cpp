/*
This problem was asked by Facebook.

Given a circular array, compute its maximum subarray sum in O(n) time. A subarray can be empty, and in this case the sum is 0.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.

*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return arr[0];
    }

    int currMaxSum = 0, currMinSum = 0;
    int maxSum = arr[0], minSum = arr[0];
    int totalSum = 0;
    for (size_t i = 0; i < n; i++)
    {

        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum);

        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum);

        totalSum += arr[i];
    }

    int maxCircleSum = totalSum - minSum;

    if (totalSum == minSum)
    {
        return maxSum;
    }

    return max(maxCircleSum, maxSum);
}

int main()
{
    vector<int> arr = {8, -1, 3, 4};
    cout << "Maximum subarray sum: " << maxSubarraySum(arr) << endl; // Output: 15

    arr = {-4, 5, 1, 0};
    cout << "Maximum subarray sum: " << maxSubarraySum(arr) << endl; // Output: 6

    return 0;
}