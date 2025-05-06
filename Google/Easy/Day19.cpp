/*
This problem was asked by Google.

Given two rectangles on a 2D graph, return the area of their intersection. If the rectangles don't intersect, return 0.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
and

{
    "top_left": (0, 5),
    "dimensions": (4, 3) # width, height
}
return 6.
*/
#include <bits/stdc++.h>
using namespace std;

int calculateIntersectionArea(pair<int, int> top_left1, pair<int, int> dimensions1, pair<int, int> top_left2, pair<int, int> dimensions2)
{
    pair<int, int> bottom_right1 = {top_left1.first + dimensions1.first, top_left1.second - dimensions1.second};
    pair<int, int> bottom_right2 = {top_left2.first + dimensions2.first, top_left2.second - dimensions2.second};

    int x_overlap = max(0, min(bottom_right1.first, bottom_right2.first) - max(top_left1.first, top_left2.first));
    int y_overlap = max(0, min(top_left1.second, top_left2.second) - max(bottom_right1.second, bottom_right2.second));

    return x_overlap * y_overlap;
}

int main()
{
    // Test case 1
    pair<int, int> top_left1 = {1, 4};
    pair<int, int> dimensions1 = {3, 3};
    pair<int, int> top_left2 = {0, 5};
    pair<int, int> dimensions2 = {4, 3};

    // Calculate area of intersection
    int area = calculateIntersectionArea(top_left1, dimensions1, top_left2, dimensions2);
    cout << "Area of intersection: " << area << endl;

    return 0;
}