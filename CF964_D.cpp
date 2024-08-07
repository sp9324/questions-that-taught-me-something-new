
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
DP is overkill in this question. it is better if done greedily.
1st just check is t is a subsequence of s using 2 pointers (and take into account wildcard) and then just
build the substring that needs to be output
*/

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        const int m = t.length();
        int j = 0;
        for (auto &x : s)
        {
            if (j == m)
            {
                if (x == '?')
                    x = 'a';
                continue;
            }
            if (x == '?') // best option would be to just set the character to t[j]
                x = t[j];
            if (x == t[j])
                j++;
        }
        if (j < m)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << s << endl;
    }
    return 0;
}

// dp solution
// bool isSubsequence(string s, string t) {
//     int n = s.length(), m = t.length();
//     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//     for (int i = 0; i <= n; ++i) dp[i][0] = true;

//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             if (s[i - 1] == t[j - 1] || s[i - 1] == '?') {
//                 dp[i][j] = dp[i - 1][j - 1];
//             }
//             dp[i][j] = dp[i][j] || dp[i - 1][j];
//         }
//     }
//     return dp[n][m];
// }

// string constructString(string s, string t) {
//     int n = s.length(), m = t.length();
//     int j = 0;
//     for (int i = 0; i < n; ++i) {
//         if (s[i] == '?') {
//             if (j < m) {
//                 s[i] = t[j++];
//             } else {
//                 s[i] = 'a';
//             }
//         } else if (s[i] == t[j]) {
//             ++j;
//         }
//     }
//     return s;
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         string s, t;
//         cin >> s >> t;
//         if (isSubsequence(s, t)) {
//             cout << "yes" << endl;
//             cout << constructString(s, t) << endl;
//         } else {
//             cout << "no" << endl;
//         }
//     }
//     return 0;
// }