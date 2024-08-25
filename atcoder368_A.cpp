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
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
i=0; i<n-k and i=n-k; i<n -> will work fine, there is no need to get confused with -1 etc.
can also use rotate method in cpp
*/

#define ll long long

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    rotate(a.begin(), a.begin() + n - k, a.end());
    // for (int i = n - k; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // for (int i = 0; i <= n - k - 2; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << a[n - k - 1] << " ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}