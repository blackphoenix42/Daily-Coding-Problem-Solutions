/*

This problem was asked by Snapchat.

Given a string of digits, generate all possible valid IP address combinations.

IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers between 0 and 255. Zero-prefixed numbers, such as 01 and 065, are not allowed, except for 0 itself.

For example, given "2542540123", you should return ['254.25.40.123', '254.254.0.123'].

*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(3^4) = O(81) = O(1)
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string &s, int start, vector<string> &path, vector<string> &result)
    {
        // Base case: if we've got 4 segments and used up all characters
        if (path.size() == 4)
        {
            if (start == s.length())
            {
                result.push_back(join(path));
            }
            return;
        }

        // Try segments of length 1 to 3
        for (int len = 1; len <= 3; ++len)
        {
            // Make sure we don't go out of bounds
            if (start + len > s.length())
                break;

            string segment = s.substr(start, len);

            if (isValid(segment))
            {
                path.push_back(segment);                 // Choose
                backtrack(s, start + len, path, result); // Explore
                path.pop_back();                         // Un-choose (Backtrack)
            }
        }
    }

    bool isValid(const string &segment)
    {
        if (segment.empty() || (segment[0] == '0' && segment.length() > 1))
            return false;

        int num = stoi(segment);
        return num >= 0 && num <= 255;
    }

    string join(const vector<string> &parts)
    {
        return parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3];
    }
};

int main()
{
    Solution sol;
    vector<string> res = sol.restoreIpAddresses("2542540123");
    for (const string &ip : res)
    {
        cout << ip << endl;
    }
    return 0;
}
