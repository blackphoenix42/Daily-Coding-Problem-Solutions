/*
This problem was asked by Amazon.

Implement a stack API using only a heap. A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)

Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap

*/

#include <bits/stdc++.h>
using namespace std;

class StackAPI
{
    priority_queue<pair<int, int>> pq;
    int c;

public:
    StackAPI() : c(0) {}
    void push(int item)
    {
        pq.push({c++, item});
    }

    int pop()
    {
        if (pq.empty())
        {
            throw out_of_range("Stack is empty");
        }

        int p = pq.top().second;
        pq.pop();
        return p;
    }
};

int main()
{
    StackAPI s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << "\n"; // 30
    cout << s.pop() << "\n"; // 20
    s.push(40);
    cout << s.pop() << "\n"; // 40
    cout << s.pop() << "\n"; // 10
    cout << s.pop() << "\n"; // error
    return 0;
}
