/*
This problem was asked by Airbnb.

You are given an array X of floating-point numbers x1, x2, ... xn. These can be rounded up or down to create a corresponding array Y of integers y1, y2, ... yn.

Write an algorithm that finds an appropriate Y array with the following properties:

The rounded sums of both arrays should be equal.
The absolute pairwise difference between elements is minimized. In other words, |x1- y1| + |x2- y2| + ... + |xn- yn| should be as small as possible.
For example, suppose your input is [1.3, 2.3, 4.4]. In this case you cannot do better than [1, 2, 5], which has an absolute difference of |1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1.

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> roundArray(vector<double> x)
{
    vector<int> y;
    vector<pair<double, int>> fracParts;

    int floorSum = 0;
    double totalSum = 0;
    int i = 0;
    for (double num : x)
    {
        int n = floor(x[i]);
        floorSum += n;
        y.push_back(n);
        totalSum += num;
        fracParts.push_back({num - n, i++});
    }

    sort(fracParts.begin(), fracParts.end(), greater<>());

    int ceils = round(totalSum) - floorSum;

    for (int i = 0; i < ceils; i++)
    {
        int idx = fracParts[i].second;
        y[idx] += 1;
    }

    return y;
}

int main()
{
    vector<double> X = {1.3, 2.3, 4.4};
    vector<int> Y = roundArray(X);

    cout << "Rounded array: ";
    for (int y : Y)
    {
        cout << y << " ";
    }
    cout << endl;

    return 0;
}