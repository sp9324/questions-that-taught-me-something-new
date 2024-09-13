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
WHAT I LEARNT:
take care of the loop condition!!!
(i originally ddnt handle the case when it was going out of bounds and m was not moving)
*/

#define ll long long
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void solveTest()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> p(n, {-1, -1});
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        p[i] = {ele - k, ele + k};
    }
    vector<int> b(m, -1);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(all(p));
    sort(all(b));

    auto it = p.begin();
    int j = 0;
    int cnt = 0;
    while (j < m && it<p.end())
    {
        if (b[j] < it->first) 
            j++;
        else if (it->first <= b[j] && it->second >= b[j])
        {
            cnt++;
            j++;
            it++;
        }
        else if (b[j] > it->second)
            it++;
    }

    cout << cnt << nl;

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int tt;
    // cin >> tt;
    // while (tt--)
    solveTest();
    return 0;
}