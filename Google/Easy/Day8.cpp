/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/

#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    unordered_set<int> targetSum(n);

    for (int i = 0; i < n; i++)
    {
        int diff = sum - arr[i];

        if (!targetSum.count(arr[i]))
        {
            targetSum.insert(diff);
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {10, 15, 3, 7};
    int k = 17;
    cout << (twoSum(arr, k) ? "true" : "false") << endl;
    return 0;
}
