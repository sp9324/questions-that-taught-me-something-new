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

/*
the pattern was right in front of my eyes! be patient with these kinds of problems.. the answer is usually right in front of you
*/

#define ll long long
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define inp(i, a, n)                   \
    for (int(i) = 0; (i) < (n); (i)++) \
        cin >> (a[(i)]);

void solveTest()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << n - 3 << " 2 1" << nl;
    else if ((n - 1) / 2 % 2 == 0)
        cout << (n - 1) / 2 - 1 << " " << (n - 1) / 2 + 1 << " 1" << nl;
    else if ((n - 1) / 2 % 2 != 0)
        cout << (n - 1) / 2 - 2 << " " << (n - 1) / 2 + 2 << " 1" << nl;
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