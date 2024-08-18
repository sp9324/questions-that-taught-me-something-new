#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
to generate all sequences, dfs may be used.
*/

int n, k;
vector<int> r;
vector<int> num;

void dfs(int now, int sum)
{
    if (now == n + 1)
    {
        if (sum % k != 0)
            return;
        for (int i : num)
        {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= r[now]; i++) // For each position, the function tries all possible values (from 1 to the upper bound for that position).
    {
        num.push_back(i);
        dfs(now + 1, (sum + i) % k);
        num.pop_back();
    }
}
signed main()
{
    cin >> n >> k;
    r.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    dfs(1, 0);
    return 0;
}