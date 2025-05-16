/*
This problem was asked by Amazon.

Given a string, find the length of the smallest window that contains every distinct character. Characters may appear more than once in the window.

For example, given "jiujitsu", you should return 5, corresponding to the final five letters. |
*/

#include <bits/stdc++.h>
using namespace std;

int min_window(string s)
{
    int n = s.size();
    if (n == 0)
        return 0;

    unordered_set<char> uniqueChars(s.begin(), s.end());
    int totalUnique = uniqueChars.size();

    unordered_map<char, int> windowCount;
    int minLen = INT_MAX;
    int start = 0;
    int uniqueInWindow = 0;

    for (int end = 0; end < n; ++end)
    {
        char rightChar = s[end];
        windowCount[rightChar]++;

        if (windowCount[rightChar] == 1)
            uniqueInWindow++;

        while (uniqueInWindow == totalUnique)
        {
            int windowSize = end - start + 1;
            if (windowSize < minLen)
                minLen = windowSize;

            char leftChar = s[start];
            windowCount[leftChar]--;
            if (windowCount[leftChar] == 0)
                uniqueInWindow--;
            start++;
        }
    }

    return minLen;
}

int main()
{
    string s = "jiujitsu";
    cout << "Minimum window length: " << min_window(s) << endl;
    return 0;
}