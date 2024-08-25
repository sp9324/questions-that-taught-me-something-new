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
don't waste time if it can be solved by brute force when constraints are low.
the idea behind optimal is:
total sum is decreased by 2 each time, so we get one of the upper bounds sum/2
the other upper bound comes from the fact that the max ele may be greater than the sum of the rest of the eles, 
so it would make no sense to keep decreasing it after it is the only positive integer left.
*/

#define ll long long

int main()
{

    int n;
    cin >> n;
    vector<int> a(n, -1);
    int mx = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }

    // sort(a.rbegin(), a.rend());
    // int ops = 0;
    // while (a[0] > 0 && a[1] > 0)
    // {

    //     a[0]--;
    //     a[1]--;
    //     ops++;

    //     sort(a.rbegin(), a.rend());
    // }

    // cout << ops << endl;

    int sumMx = sum - mx;
    cout << min(sum / 2, sumMx) << endl;

    return 0;
}