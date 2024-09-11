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

/*
see usaco guide for solution
don't directly use slopes as division causes problems.
*/

void solveTest()
{
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate the cross product
    ll cross_product = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);

    if (cross_product == 0)
        cout << "TOUCH" << nl;
    else if (cross_product > 0)
        cout << "LEFT" << nl;
    else
        cout << "RIGHT" << nl;
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