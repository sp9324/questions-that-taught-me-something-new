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
THIS is the brute force approach (TLE)
but i learnt a new thing: prefix sum array is created of n+1 size (the first element is taken as 0) -> that's why 
a negative max prefix sum is never an answer lol
*/

#define ll long long
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int getMaxInRange(vector<int> &x, int a, int b)
{
    int mx = INT_MIN;
    vector<int> p;
    p.push_back(x[a - 1]);
    mx = max(mx, p.back());
    for (int i = a; i < b; i++)
    {

        p.push_back(p.back() + x[i]);
        mx = max(mx, p.back());
    }
    return mx;
}

void solveTest()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<int> res;
    for (int i = 0; i < q; i++)
    {
        
        int op, f, s;
        cin >> op >> f >> s;
        if (op == 2)
        {
            int a = f, b = s;
            int ans = getMaxInRange(x, a, b);
            if (ans >= 0)
                res.push_back(ans);
            else
                res.push_back(0);
        }
        else if (op == 1)
        {
            int k = f, u = s;
            x[k - 1] = u;
        }
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << nl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solveTest();
    return 0;
}