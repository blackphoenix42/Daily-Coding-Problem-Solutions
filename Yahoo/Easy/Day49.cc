/*
This problem was asked by Yahoo.

You are given a string of length N and a parameter k. The string can be manipulated by taking one of the first k letters and moving it to the end.

Write a program to determine the lexicographically smallest string that can be created after an unlimited number of moves.

For example, suppose we are given the string daily and k = 1. The best we can create in this case is ailyd.

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getLexicographicallySmallestString(string s, int k)
{
    if (k == 1)
    {
        string result = s;
        for (int i = 1; i < s.size(); i++)
        {
            string rotated = s.substr(i) + s.substr(0, i);
            result = min(result, rotated);
        }
        return result;
    }
    else
    {
        sort(s.begin(), s.end());
        return s;
    }
}

int main()
{
    string s = "daily";
    int k = 1;

    string result = getLexicographicallySmallestString(s, k);
    cout << "Lex smallest string: " << result << endl;

    return 0;
}
