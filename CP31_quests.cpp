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
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
dp doesnt mean the traditional format has to be followed.
*/

#define ll long long

void solveTest()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n, -1);
    vector<int> b(n, -1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int mx = INT_MIN;

    ll ans = 0;
    ll res=0;
    for (int i = 0; i < min(n, k); i++)
    {
        res += a[i];
        mx = max(mx, b[i]);
        ans = max(ans, res + mx * (k - i - 1));
    }
    cout << ans << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solveTest();
    return 0;
}