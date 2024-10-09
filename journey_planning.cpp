#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>
#include <map>
#include <climits>
#include <iomanip>
#include <stack>
#include <list>
#include <bitset>
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
i thought dp. but a simple observation in the condition leads to this solution
c[i+1]-b[c[i+1]]==c[i]-b[i] means that i-b[i] should be same for all cities selected.
*/

void solveTest()
{
    int n;
    cin >> n;
    vector<ll> b(n, -1);
    ll mx = 0;
    map<int, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mp[i - b[i]] += b[i];
    }

    for (auto it : mp)
    {
        mx = max(mx, it.second);
    }

    cout << mx << nl;
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