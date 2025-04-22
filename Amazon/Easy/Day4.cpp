/*
This problem was asked by Amazon.

You are given a list of data entries that represent entries and exits of groups of people into a building. An entry looks like this:

{"timestamp": 1526579928, count: 3, "type": "enter"}

This means 3 people entered the building. An exit looks like this:

{"timestamp": 1526580382, count: 2, "type": "exit"}

This means that 2 people exited the building. timestamp is in Unix time (https://en.wikipedia.org/wiki/Unix_time).

Find the busiest period in the building, that is, the time with the most people in the building. Return it as a pair of (start, end) timestamps. You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findBusiestPeriod(vector<pair<int, int>> data)
{
    int currentCount = 0, maxCount = 0;
    int startTime = 0, endTime = 0;
    pair<int, int> busiestPeriod;

    for (size_t i = 0; i < data.size(); ++i)
    {
        currentCount += data[i].second;

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
            startTime = data[i].first;
            endTime = (i + 1 < data.size()) ? data[i + 1].first : startTime;
            busiestPeriod = {startTime, endTime};
        }
    }

    return busiestPeriod;
}

int main()
{
    vector<pair<int, int>> data = {
        {1526579928, 3},
        {1526580382, -2},
        {1526580385, 5},
        {1526580390, -1}};

    pair<int, int> result = findBusiestPeriod(data);
    cout << "Busiest period: (" << result.first << ", " << result.second << ")" << endl;

    return 0;
}