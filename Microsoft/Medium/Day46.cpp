/*
This problem was asked by Microsoft.

Write a program to determine how many distinct ways there are to create a max heap from a list of N given integers.

For example, if N = 3, and our integers are [1, 2, 3], there are two ways, shown below.

  3      3
 / \    / \
1   2  2   1

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100

vector<ll> dp(MAXN, -1);
vector<vector<ll>> nCrMemo(MAXN, vector<ll>(MAXN, -1));

// Compute C(n, k) using memoization
ll nCr(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    if (nCrMemo[n][k] != -1)
        return nCrMemo[n][k];
    return nCrMemo[n][k] = nCr(n - 1, k - 1) + nCr(n - 1, k);
}

// Compute number of nodes in left subtree
int getLeftSubtreeSize(int n)
{
    if (n == 0)
        return 0;
    int h = log2(n);
    int maxNodesAtH = (1 << h); // 2^h
    int nodesBeforeH = maxNodesAtH - 1;
    int remaining = n - nodesBeforeH;

    int left = nodesBeforeH;
    if (remaining < maxNodesAtH / 2)
        left = nodesBeforeH - ((maxNodesAtH / 2) - remaining);

    return left;
}

ll countHeaps(int n)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    int L = getLeftSubtreeSize(n);
    ll ans = nCr(n - 1, L) * countHeaps(L) * countHeaps(n - 1 - L);
    return dp[n] = ans;
}

int main()
{
    int N = 4;
    vector<int> arr = {1, 2, 3, 4};

    cout << "Sample Input: [";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i];
        if (i != N - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << "Number of distinct max heaps: " << countHeaps(N) << endl;

    return 0;
}
