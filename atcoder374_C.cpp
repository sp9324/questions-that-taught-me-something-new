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
LEARNT ABOUT BITMASKS!
my first problem using bitmasks. super easy (refer leetcode "Subsets" problem for full detail on bitmasks)
*/


ll mini = LLONG_MAX;

void solveTest()
{
    int n;
    cin >> n;
    vector<int> k(n, -1);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        sum += k[i];
    }

    ll mini = LLONG_MAX;
    int nthBit = 1 << n;
    for (int i = 1; i < power(2, n) - 1; i++)
    {
        string bitmask = bitset<32>(i | nthBit).to_string().substr(32 - n);
        ll mx = LLONG_MIN;
        ll A = 0;
        for (int j = 0; j < n; j++)
        {
            if (bitmask.at(j) == '1')
                A += k[j];
        }
        mx = max(A, sum - A);
        mini = min(mx, mini);
    }
    cout << mini << nl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int tt;
    // cin >> tt;
    // while(tt--)
    solveTest();
    return 0;
}