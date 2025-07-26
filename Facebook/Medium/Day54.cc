/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "111";
    int n = (int)s.size();

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // empty prefix
    dp[1] = 1;  // '1' → 'a'

    for (int i = 2; i <= n; i++) {
        // single-digit decode
        if (s[i - 1] != '0') dp[i] += dp[i - 1];
        // two-digit decode
        int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (two >= 10 && two <= 26) dp[i] += dp[i - 2];
    }

    // prints 3 for "111"
    cout << dp[n] << "\n";

    return 0;
}