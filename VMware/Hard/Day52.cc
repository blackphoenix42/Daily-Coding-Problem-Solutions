/*
The skyline of a city is composed of several buildings of various widths and heights, possibly overlapping one another when viewed from a distance. We can represent the buildings using an array of `(left, right, height)` tuples, which tell us where on an imaginary x-axis a building begins and ends, and how tall it is. The skyline itself can be described by a list of `(x, height)` tuples, giving the locations at which the height visible to a distant observer changes, and each new height.

Given an array of buildings as described above, create a function that returns the skyline.

For example, suppose the input consists of the buildings `[(0, 15, 3), (4, 11, 5), (19, 23, 4)]`. In aggregate, these buildings would create a skyline that looks like the one below.

```
     ______
    |      |        ___
 ___|      |___    |   |
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
```

As a result, your function should return `[(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)]`.
*/

#include <bits/stdc++.h>
using namespace std;

// Event struct: x-coordinate, height, start/end marker
struct Event {
    int x, height;
    bool isStart;
    Event(int x, int height, bool isStart)
        : x(x), height(height), isStart(isStart) {}
};

// Custom sorting for events
bool cmp(const Event& a, const Event& b) {
    if (a.x != b.x) return a.x < b.x;

    // If same x:
    // Start events before end events
    if (a.isStart != b.isStart) return a.isStart;

    // Among starts: higher height first
    if (a.isStart) return a.height > b.height;
    // Among ends: lower height first
    return a.height < b.height;
}

vector<pair<int, int>> getSkyline(vector<tuple<int, int, int>>& buildings) {
    vector<Event> events;

    // Convert each building into two events
    for (auto& b : buildings) {
        int left = get<0>(b), right = get<1>(b), height = get<2>(b);
        events.emplace_back(left, height, true);    // Start of building
        events.emplace_back(right, height, false);  // End of building
    }

    // Sort events
    sort(events.begin(), events.end(), cmp);

    // Max-heap using multiset to store active building heights
    multiset<int> heights = {0};  // Initialize with ground level
    int prevMax = 0;

    vector<pair<int, int>> result;

    for (auto& e : events) {
        if (e.isStart) {
            heights.insert(e.height);
        } else {
            heights.erase(heights.find(e.height));  // Erase one instance
        }

        int currMax = *heights.rbegin();  // Current max height

        if (currMax != prevMax) {
            result.emplace_back(e.x, currMax);
            prevMax = currMax;
        }
    }

    return result;
}

int main() {
    vector<tuple<int, int, int>> buildings = {
        {0, 15, 3}, {4, 11, 5}, {19, 23, 4}};

    vector<pair<int, int>> skyline = getSkyline(buildings);

    for (auto& p : skyline) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
