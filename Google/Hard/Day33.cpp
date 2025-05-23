/*
This problem was asked by Google.

Given a string, split it into as few strings as possible such that each string is a palindrome.

For example, given the input string racecarannakayak, return ["racecar", "anna", "kayak"].

Given the input string abc, return ["a", "b", "c"].
*/

#include <bits/stdc++.h>

using namespace std;

// Helper function to check and mark all palindromes in the string
vector<vector<bool>> computePalindromeTable(const string &s)
{
    int n = s.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // Every single character is a palindrome
    for (int i = 0; i < n; ++i)
        isPalindrome[i][i] = true;

    // Check for 2-character palindromes
    for (int i = 0; i < n - 1; ++i)
        isPalindrome[i][i + 1] = (s[i] == s[i + 1]);

    // Check for palindromes of length > 2
    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
        }
    }

    return isPalindrome;
}

// Function to split the string into minimum number of palindromic substrings
vector<string> minPalindromePartition(const string &s)
{
    int n = s.size();
    auto isPalindrome = computePalindromeTable(s);

    vector<int> dp(n, 0);    // dp[i] = min cuts for s[0..i]
    vector<int> prev(n, -1); // prev[i] = previous cut position for path reconstruction

    for (int i = 0; i < n; ++i)
    {
        if (isPalindrome[0][i])
        {
            dp[i] = 0; // no cut needed if s[0..i] is palindrome
            prev[i] = -1;
        }
        else
        {
            dp[i] = i; // max cuts possible
            for (int j = 0; j < i; ++j)
            {
                if (isPalindrome[j + 1][i] && dp[j] + 1 < dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }

    // Reconstruct the palindromic substrings from `prev`
    vector<string> result;
    int idx = n - 1;
    while (idx >= 0)
    {
        int start = prev[idx] + 1;
        result.push_back(s.substr(start, idx - start + 1));
        idx = prev[idx];
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s1 = "racecarannakayak";
    string s2 = "abc";

    auto res1 = minPalindromePartition(s1);
    auto res2 = minPalindromePartition(s2);

    cout << "Input: " << s1 << "\nOutput: ";
    for (auto &p : res1)
        cout << "\"" << p << "\" ";
    cout << endl;

    cout << "Input: " << s2 << "\nOutput: ";
    for (auto &p : res2)
        cout << "\"" << p << "\" ";
    cout << endl;

    return 0;
}
