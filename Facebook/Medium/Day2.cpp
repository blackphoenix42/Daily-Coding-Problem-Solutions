/*
This problem was asked by Facebook.

Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't split it up into two subsets that add up to the same sum.
*/
#include <bits/stdc++.h>
using namespace std;

// Top Down Approach With Memoization
/*
bool topDown(vector<int> &arr, int n, int subsetSum, vector<vector<bool>> &memo)
{

    if (subsetSum == 0)
    {
        return true;
    }

    if (n == 0 or subsetSum < 0)
    {
        return false;
    }

    if (memo[n][subsetSum] != NULL)
    {
        return memo[n][subsetSum];
    }

    bool res = topDown(arr, n - 1, subsetSum - arr[n - 1], memo) || topDown(arr, n - 1, subsetSum, memo);
    memo[n][subsetSum] = res;
    return res;
}
    */

// Bottom Up approach Time: O(N * target) Space : O(target)
bool bottomUp(vector<int> &arr, int target)
{
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr)
    {
        for (int j = target; j >= num; --j)
        {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

bool canPartition(vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 != 0)
        return false;
    int target = sum / 2;
    int n = arr.size();
    vector<vector<bool>> memo(n + 1, vector<bool>(target + 1, NULL));
    // topDown(arr, n - 1, target, memo);
    return bottomUp(arr, target);
}

int main()
{
    vector<int> arr = {15, 5, 20, 10, 35, 15, 10};
    cout << (canPartition(arr) ? "true" : "false") << endl; // true
    arr = {15, 5, 20, 10, 35};
    cout << (canPartition(arr) ? "true" : "false") << endl; // false
    return 0;
}