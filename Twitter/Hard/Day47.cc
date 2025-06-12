/*
You are given an array of length 24, where each element represents the number of new subscribers during the corresponding hour. Implement a data structure that efficiently supports the following:

update(hour: int, value: int): Increment the element at index hour by value.
query(start: int, end: int): Retrieve the number of subscribers that have signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day, and that you will not be asked for start and end values that wrap around midnight.
*/

#include <vector>
#include <iostream>
using namespace std;

class SubscriberCounter
{
private:
    vector<int> bit; // Fenwick Tree
    int n;

    // Get sum of elements from 0 to index
    int prefixSum(int index)
    {
        int result = 0;
        index++; // BIT is 1-based
        while (index > 0)
        {
            result += bit[index];
            index -= index & (-index); // move to parent
        }
        return result;
    }

public:
    vector<int> arr; // Original array for clarity

    SubscriberCounter(int size = 24)
    {
        n = size;
        bit.assign(n + 1, 0);
        arr.assign(n, 0);
    }

    // Increment subscribers at hour by value
    void update(int hour, int value)
    {
        arr[hour] += value; // Optional: keep original array updated
        hour++;             // BIT is 1-based
        while (hour <= n)
        {
            bit[hour] += value;
            hour += hour & (-hour); // move to next responsible node
        }
    }

    // Query sum between start and end (inclusive)
    int query(int start, int end)
    {
        return prefixSum(end) - prefixSum(start - 1);
    }

    // Clear everything (for end of day)
    void reset()
    {
        fill(bit.begin(), bit.end(), 0);
        fill(arr.begin(), arr.end(), 0);
    }
};

// Example usage
int main()
{
    SubscriberCounter counter;

    counter.update(1, 5); // 5 subscribers at hour 1
    counter.update(3, 2); // 2 subscribers at hour 3
    counter.update(5, 7); // 7 subscribers at hour 5

    cout << "Subscribers from hour 0 to 5: " << counter.query(0, 5) << endl;
    cout << "Subscribers from hour 2 to 4: " << counter.query(2, 4) << endl;

    counter.reset(); // At end of day
    cout << "After reset, subscribers from hour 0 to 5: " << counter.query(0, 5) << endl;

    return 0;
}
