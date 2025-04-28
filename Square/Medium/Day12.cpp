/*
This problem was asked by Square.

Given a list of words, return the shortest unique prefix of each word. For example, given the list:

dog
cat
apple
apricot
fish

Return the list:

d
c
app
apr
f
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> shortest_unique_prefix(vector<string> words)
{
    unordered_map<string, int> prefix_count;
    vector<string> result;

    for (const string &word : words)
    {
        for (int i = 1; i <= word.size(); ++i)
        {
            string prefix = word.substr(0, i);
            prefix_count[prefix]++;
        }
    }

    for (const string &word : words)
    {
        for (int i = 1; i <= word.size(); ++i)
        {
            string prefix = word.substr(0, i);
            if (prefix_count[prefix] == 1)
            {
                result.push_back(prefix);
                break;
            }
        }
    }

    return result;
}

int main()
{
    vector<string> words = {"dog", "cat", "apple", "apricot", "fish"};
    vector<string> result = shortest_unique_prefix(words);
    for (string s : result)
    {
        cout << s << endl;
    }
    return 0;
}