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
we will always pick the numbers 2k-1, 2k, 2k+1 because we need at least 2 odd and 2 even. this comes out to mean
there will be floor(cnt/2) triplets
*/

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        for (int i = l; i <= r; i++)
        {
            if (i % 2 != 0)
                cnt++;
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}