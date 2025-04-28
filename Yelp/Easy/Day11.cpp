/*
This problem was asked by Yelp.

Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent. You can assume each valid number in the mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
*/
#include <bits/stdc++.h>
using namespace std;

void getCombinations(unordered_map<char, vector<string>> mapping, string digits, int idx, string temp, vector<string> &result)
{
    if (temp.length() == digits.length())
    {
        result.push_back(temp);
        return;
    }

    vector<string> s = mapping[digits[idx]];

    for (auto c : s)
    {
        temp += c;
        getCombinations(mapping, digits, idx + 1, temp, result);
        temp.pop_back();
    }
}

int main()
{
    unordered_map<char, vector<string>> mapping;
    mapping['2'] = {"a", "b", "c"};
    mapping['3'] = {"d", "e", "f"};
    mapping['4'] = {"g", "h", "i"};
    mapping['5'] = {"j", "k", "l"};
    mapping['6'] = {"m", "n", "o"};
    mapping['7'] = {"p", "q", "r", "s"};
    mapping['8'] = {"t", "u", "v"};
    mapping['9'] = {"w", "x", "y", "z"};

    string digits = "23";
    vector<string> result;

    getCombinations(mapping, digits, 0, "", result);

    for (string s : result)
    {
        cout << s << " ";
    }

    return 0;
}