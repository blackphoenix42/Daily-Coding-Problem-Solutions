/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> productArray(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, 1);

    for (int i = 1; i < n; i++)
    {
        result[i] = result[i - 1] * arr[i - 1];
    }

    int suffixProduct = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffixProduct *= arr[i + 1];
        result[i] *= suffixProduct;
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result = productArray(arr);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}