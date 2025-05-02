/*
This problem was asked by Oracle.

We say a number is sparse if there are no adjacent ones in its binary representation. For example, 21 (10101) is sparse, but 22 (10110) is not. For a given input N, find the smallest sparse number greater than or equal to N.

Do this in faster than O(N log N) time.
*/

#include <bits/stdc++.h>
using namespace std;

// Time : O(logn)
// Space : O(logn)
int findSparseNumber(int n)
{
    vector<bool> arr;

    while (n != 0)
    {
        arr.push_back(n & 1);
        n >>= 1;
    }

    arr.push_back(false);
    int x = arr.size();
    int finalChange = 0;
    for (int i = 1; i < x - 1; i++)
    {
        if (arr[i] == true and arr[i - 1] == true and arr[i + 1] == false)
        {
            arr[i + 1] = true;

            for (int j = i; j >= finalChange; j--)
            {
                arr[j] = false;
            }

            finalChange = i + 1;
        }
    }

    int ans = 0;
    for (int k = 0; k < x; k++)
    {
        ans += arr[k] * (1 << k);
    }

    return ans;
}

int main()
{
    int n = 22;
    cout << "Input: " << n << endl;
    cout << "Output: " << findSparseNumber(n) << endl;
    return 0;
}