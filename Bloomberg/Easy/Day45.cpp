/*
This problem was asked by Bloomberg.

Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool hasOneToOneMapping(const string &s1, const string &s2)
{
    if (s1.length() != s2.length())
        return false;

    unordered_map<char, char> mapping;
    unordered_set<char> mapped_chars;

    for (int i = 0; i < s1.length(); i++)
    {
        char c1 = s1[i];
        char c2 = s2[i];

        if (mapping.count(c1))
        {
            if (mapping[c1] != c2)
                return false;
        }
        else
        {
            if (mapped_chars.count(c2))
                return false;
            mapping[c1] = c2;
            mapped_chars.insert(c2);
        }
    }

    return true;
}

int main()
{
    string s1 = "foo";
    string s2 = "bar";

    if (hasOneToOneMapping(s1, s2))
        cout << "Exists";
    else
        cout << "Doesn't exist";

    return 0;
}
