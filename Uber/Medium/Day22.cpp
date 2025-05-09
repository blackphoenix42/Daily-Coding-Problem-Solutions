/*
This problem was asked by Uber.

Implement a 2D iterator class. It will be initialized with an array of arrays, and should implement the following methods:

- next(): returns the next element in the array of arrays. If there are no more elements, raise an exception.
- has_next(): returns whether or not the iterator still has elements left.

For example, given the input [[1, 2], [3], [], [4, 5, 6]], calling next() repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays. Some of the arrays can be empty.

*/

#include <bits/stdc++.h>
using namespace std;

class Iterator
{
    int currIdx;
    vector<vector<int>> arr;
    vector<vector<int>::iterator> start;
    vector<vector<int>::iterator> end;

public:
    Iterator(vector<vector<int>> &arr)
    {
        this->arr = arr;
        int n = arr.size();
        start.resize(n);
        end.resize(n);
        currIdx = 0;

        for (int i = 0; i < n; i++)
        {
            start[i] = arr[i].begin();
            end[i] = arr[i].end();
        }
    }

    bool has_next()
    {
        for (int i = currIdx; i < arr.size(); i++)
        {
            if (start[i] != end[i])
            {
                return true;
            }
        }

        return false;
    }

    int next()
    {
        try
        {
            if (!has_next())
            {
                throw runtime_error("No more Element");
            }

            if (start[currIdx] == end[currIdx])
            {
                currIdx++;
                return next();
            }
            else
            {
                return *start[currIdx]++;
            }
        }
        catch (runtime_error &e)
        {
            cerr << "Exception Caught: " << e.what() << endl;
        }
        return INT_MIN;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2}, {3}, {}, {4, 5, 6}};
    Iterator it(arr);
    while (it.has_next())
    {
        cout << it.next() << " ";
    }

    // Check Exception
    it.next();

    return 0;
}
