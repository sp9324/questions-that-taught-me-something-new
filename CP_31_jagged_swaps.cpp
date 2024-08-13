// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <utility>
// #include <iterator>
// #include <cmath>
// #include <limits>
#include <bits/stdc++.h>
using namespace std;

/*
WJAT I LEARNT:
1. take the entire vector as input otherwise you'll face errors
2. try using proof by induction to prove other things if one has already been proven
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // cout << "a[1] " << a[1] << endl;
        if (a[0] != 1)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }

// to find number of swaps
        // int ans = 0;
        // for (int i = 2; i <= n - 1; i++)
        // {
        //     if (a[i] > a[i - 1] && a[i] > a[i + 1])
        //     {
        //         ans += (i - a[i]);
        //     }
        // }
    }
    return 0;
}