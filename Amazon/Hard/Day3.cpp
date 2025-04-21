/*
This problem was asked by Amazon.

Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas" is "anana".
*/
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    int len = s.length();
    int left = i;
    int right = j - 1;

    while (left < right)
    {
        if (s[left++] != s[right--])
        {
            return false;
        }
    }

    return true;
}

// Brute Force Time: O(n^3) Space: O(1)
string longest_palindromic_substring(string s)
{
    int len = s.length();

    for (int i = len; i > 0; i--)
    {
        for (int st = 0; st <= len - i; st++)
        {
            if (checkPalindrome(s, st, st + i))
            {
                return s.substr(st, i);
            }
        }
    }
    return "";
}

// Expand Around Centre Approach, Time: O(n^2), Space: O(1)
string lps(string s)
{
    int len = s.size();

    auto expand = [&](int left, int right)
    {
        while (left >= 0 and right < len and s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    };
    string maxStr = s.substr(0, 1);
    for (int i = 0; i < len - 1; i++)
    {
        string a = expand(i, i);
        string b = expand(i, i + 1);
        if (a.size() > maxStr.size())
            maxStr = a;
        if (b.size() > maxStr.size())
            maxStr = b;
    }

    return maxStr;
}

int main()
{
    string s1 = "aabcdcb";
    string s2 = "bananas";
    cout << "Longest palindromic substring of " << s1 << " is: " << lps(s1) << endl;
    cout << "Longest palindromic substring of " << s2 << " is: " << lps(s2) << endl;
    return 0;
}