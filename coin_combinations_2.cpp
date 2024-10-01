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

#define ll long long
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define inp(i, a, n)                   \
    for (int(i) = 0; (i) < (n); (i)++) \
        cin >> (a[(i)]);
const ll mod = 1e9 + 7;

ll power(ll x, ll y)
{
    ll ans = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            ans = (ans * x) % mod;
        }
        y = y / 2;
        x = (x * x) % mod;
    }
    return ans;
}

ll modInverse(ll n)
{
    return power(n, mod - 2);
}

vector<ll> factorial(1e6 + 5, 0);
void getFactorial()
{
    factorial[0] = 1;
    for (ll i = 1; i <= 1e6; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

ll nCr(ll n, ll r)
{
    if (n < r)
    {
        return 0;
    }
    if (r == 0)
    {
        return 1;
    }
    return (((factorial[n] * modInverse(factorial[r]))) % mod * (modInverse(factorial[n - r])) % mod) % mod;
}


/*
We'll let $\texttt{dp}[w]$ equal the number of ordered ways to add the coins up
to $w$. In the previous problem, we tried out each coin for each possible $w$.
Here, we'll do the reverse, looping through all possible $w$ ($0\leq w \leq x$)
for each coin $i$ while updating $\texttt{dp}$ as follows:

$$\texttt{dp}[w] := \texttt{dp}[w] + \texttt{dp}[w-\texttt{coins}[i]]$$

This essentially entails switching the order of the nested loops from the
previous problem. Since we now loop over the coins before the weights, we only
go through the set of coins once, so it's impossible to create two combinations
with the same set of coins ordered differently.
*/

void solveTest()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n, -1);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - c[i] >= 0)
                dp[j] = (dp[j] + dp[j - c[i]]) % mod;
        }
    }

    int ans = dp[x];
    cout << ans << "\n";
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