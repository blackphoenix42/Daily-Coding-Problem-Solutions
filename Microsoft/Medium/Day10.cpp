/*
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

#include <bits/stdc++.h>
using namespace std;


vector<string> wordBreak(vector<string> &words, string s)
{
    unordered_set<string> wordSet(words.begin(), words.end());
    vector<string> result;
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (dp[j] && wordSet.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }

    if (!dp[n])
        return result; 
    
    int end = n;
    for (int i = n - 1; i >= 0; --i)
    {
        if (dp[i] && wordSet.count(s.substr(i, end - i)))
        {
            result.push_back(s.substr(i, end - i));
            end = i;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<string> words = {"quick", "brown", "the", "fox"};
    string s = "thequickbrownfox";
    vector<string> result = wordBreak(words, s);
    for (string word : result)
    {
        cout << word << " ";
    }
    cout << endl;

    words = {"bed", "bath", "bedbath", "and", "beyond"};
    s = "bedbathandbeyond";
    result = wordBreak(words, s);
    for (string word : result)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}