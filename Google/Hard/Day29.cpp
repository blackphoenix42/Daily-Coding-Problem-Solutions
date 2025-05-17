/*
This problem was asked by Google.

Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
*/

#include <bits/stdc++.h>
using namespace std;

bool subsetSumDP(const vector<int> &S, int k, int index,
                 map<pair<int, int>, bool> &memo,
                 vector<int> &result)
{
    if (k == 0)
        return true;
    if (index >= S.size() || k < 0)
        return false;

    pair<int, int> key = {index, k};
    if (memo.count(key))
        return memo[key];

    // Include current element
    result.push_back(S[index]);
    if (subsetSumDP(S, k - S[index], index + 1, memo, result))
    {
        memo[key] = true;
        return true;
    }
    result.pop_back(); // backtrack

    // Exclude current element
    if (subsetSumDP(S, k, index + 1, memo, result))
    {
        memo[key] = true;
        return true;
    }

    memo[key] = false;
    return false;
}

vector<int> subsetSum(const vector<int> &S, int k)
{
    map<pair<int, int>, bool> memo;
    vector<int> result;
    if (subsetSumDP(S, k, 0, memo, result))
    {
        return result;
    }
    return {}; 
}

int main()
{
    vector<int> S = {12, 1, 61, 5, 9, 2};
    int k = 24;

    vector<int> result = subsetSum(S, k);

    if (!result.empty())
    {
        cout << "Subset that sums to " << k << ": ";
        for (int num : result)
            cout << num << " ";
        cout << endl;
    }
    else
    {
        cout << "No subset found that sums to " << k << endl;
    }

    return 0;
}
