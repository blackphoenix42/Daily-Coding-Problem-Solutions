/*
This problem was asked by Epic.

The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the digits appearing in the previous term. The first few terms are as follows:

1
11
21
1211
111221
As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

Given an integer N, print the Nth term of this sequence.
*/

#include <bits/stdc++.h>
using namespace std;

int lookAndSay(int n)
{
    if (n == 1)
        return 1;

    int dig = 1;

    for (int i = 1; i < n; i++)
    {
        string prev = to_string(dig);
        string s = "";
        int cnt = 1;
        for (int c = 1; c < prev.length(); c++)
        {
            if (prev[c] == prev[c - 1])
            {
                cnt++;
            }
            else
            {
                s += to_string(cnt);
                s += prev[c - 1];
                cnt = 1;
            }
        }

        s += to_string(cnt);
        s += prev[prev.length() - 1];
        dig = stoi(s);
    }

    return dig;
}

int main()
{
    cout << "The 1st term of the look and say sequence is: " << lookAndSay(1) << endl;
    cout << "The 2nd term of the look and say sequence is: " << lookAndSay(2) << endl;
    cout << "The 3rd term of the look and say sequence is: " << lookAndSay(3) << endl;
    cout << "The 4th term of the look and say sequence is: " << lookAndSay(4) << endl;
    cout << "The 5th term of the look and say sequence is: " << lookAndSay(5) << endl;
    cout << "The 6th term of the look and say sequence is: " << lookAndSay(6) << endl;
    return 0;
}