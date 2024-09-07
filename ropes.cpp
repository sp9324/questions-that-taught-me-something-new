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

int prd(vector<int> &a, int k, double x)
{
    if (x == 0)
        return true;
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
        cnt += a[i] / x;
    return cnt >= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    double l = 0, r = *max_element(a.begin(), a.end()), mid;
    int lp = 100; // we take 100 iterations as log2(1e7) is tiny, so 100 will definitely work. everything is in float so better to take this.
    while (lp--)
    {
        mid = l + (r - l) / 2;
        if (prd(a, k, mid))
            l = mid; // because we might miss values in between
        else
            r = mid; // because we might miss values in between
    }
    cout << setprecision(16) << l << '\n'; // as the pattern is TTTTFFFFFFFF
}
