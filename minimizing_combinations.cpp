#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>
#include <numeric>
#include <map>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
glad to have done this on my own! :)
(direct dp, no recursive sol haha)
i needed to use ll for ans instead of int because at places we are adding 1 to int_max, so we have to be careful!!!
*/

#define ll long long
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void solveTest()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n, -1);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    // sort(c.rbegin(), c.rend());
    vector<ll> dp(x + 1, INT_MAX); // 0 to x
    dp[0] = 0;
    for (int i = 1; i <= x; i++) // amount
    {
        for (int j = 0; j < n; j++) // coins
        {
            if (i - c[j] >= 0)
            {
                ll ans = 1 + dp[i - c[j]];
                dp[i] = min(ans, dp[i]);
            }
            // cout<<dp[i]<<nl;
        }
    }

    if (dp[x] == INT_MAX)
        cout << "-1" << nl;
    else
        cout << dp[x] << nl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int tt;
    // cin >> tt;
    // while (tt--)
    solveTest();
    return 0;
}