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

// #define ll long long
#define nl "\n"
#define all(x) (x).begin(), (x).end()

/*
WHAT I LEARNT:
i tried dp initially
then i read a bit of the editorial and realized finding minimium k etc means TTTFFF.. pattern. so binary search
but i overcomplicated predicate.
*/

bool check(int k, const vector<pair<int, int>> &seg)
{
    int ll = 0, rr = 0;
    for (const auto &e : seg)
    {
        ll = max(ll - k, e.first);
        rr = min(rr + k, e.second);
        if (ll > rr)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> seg[i].first >> seg[i].second;
    }

    int l = -1, r = 1e9;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid, seg))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}