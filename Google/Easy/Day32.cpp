/*
This problem was asked by Google.

You are given given a list of rectangles represented by min and max x- and y-coordinates. Compute whether or not a pair of rectangles overlap each other. If one rectangle completely covers another, it is considered overlapping.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
return true as the first and third rectangle overlap each other.
*/

// rectangles.cpp
#include <iostream>
#include <vector>
using namespace std;

struct Rectangle
{
    int x, y;
    int w, h;

    // Convert to [left, right) × (bottom, top] interval form
    int left() const { return x; }
    int right() const { return x + w; } // exclusive
    int top() const { return y; }
    int bottom() const { return y - h; } // inclusive
};

bool overlaps(const Rectangle &a, const Rectangle &b)
{
    // One rectangle is completely to the left of the other
    if (a.right() <= b.left() || b.right() <= a.left())
        return false;

    // One rectangle is completely above the other
    if (a.bottom() >= b.top() || b.bottom() >= a.top())
        return false;

    return true; // otherwise intervals intersect on both axes
}

// Return true as soon as *any* pair overlaps
bool anyPairOverlaps(const vector<Rectangle> &rects)
{
    const size_t n = rects.size();
    for (size_t i = 0; i < n; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if (overlaps(rects[i], rects[j]))
                return true;
    return false;
}

int main()
{
    vector<Rectangle> rects = {
        {1, 4, 3, 3},  // top_left (1,4),  w=3, h=3
        {-1, 3, 2, 1}, // top_left (-1,3), w=2, h=1
        {0, 5, 4, 3}   // top_left (0,5),  w=4, h=3
    };

    cout << boolalpha
         << anyPairOverlaps(rects) // → true
         << '\n';
    return 0;
}
