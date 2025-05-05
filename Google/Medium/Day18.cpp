/*
This problem was asked by Google.

Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. Given [1, 3, 6, 24], return [1, 3, 6, 24].
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> largestSubset(vector<int> nums)
{
    int n = nums.size();

    int maxSubsetIdx = -1;
    int maxSubsetSize = -1;

    vector<int> dp(n, 0);

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        int size = 0;
        for (int k = 0; k < i; k++)
        {
            if (nums[i] % nums[k] == 0 and size < dp[k])
            {
                size = dp[k];
            }
        }

        dp[i] = size + 1;

        if (maxSubsetSize < dp[i])
        {
            maxSubsetSize = dp[i];
            maxSubsetIdx = i;
        }
    }

    vector<int> res;
    int div = nums[maxSubsetIdx];
    int cnt = maxSubsetSize;
    for (int j = maxSubsetIdx; j >= 0; j--)
    {
        if (cnt == 0)
            break;

        if (div % nums[j] == 0 and cnt == dp[j])
        {
            res.push_back(nums[j]);
            div = nums[j];
            cnt--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> nums = {3, 5, 10, 20, 21};
    vector<int> nums1 = {1, 3, 6, 24};
    vector<int> result = largestSubset(nums);
    vector<int> result1 = largestSubset(nums1);
    cout << "Largest subset: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Largest subset 1: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}