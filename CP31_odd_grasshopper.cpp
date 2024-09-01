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
this is a less complicated solution:
if 𝑥0
 were always zero, the answer would be

−𝑛
 if 𝑛≡1mod4
1
 if 𝑛≡2mod4
𝑛+1
 if 𝑛≡3mod4
0
 if 𝑛
 is divisible by 4
Let's find an answer for the cases when 𝑥0≠0
. But if 𝑥0
 is even, then all steps will follow the same directions, and the answer will be 𝑥0+𝐷
, where 𝐷
 is the answer for the same 𝑛
 and starting point 0
 (described above). And if 𝑥0
 is odd, then all steps will have opposite directions, and the answer will be 𝑥0−𝐷
.
*/

#define ll long long

void solveTest()
{
    ll x0, n;
    cin >> x0 >> n;
    if (x0 % 2 == 0)
    {
        if (n % 4 == 0)
        {
            cout << x0 << endl;
        }
        else if (n % 4 == 1)
        {
            // if (n > 4)
            // {
            cout << x0 - (n / 4) * 4 - 1 << endl;
            // }
            // else
            // {
            //     cout << x0 - 1 << endl;
            // }
        }
        else if (n % 4 == 2)
        {
            cout << x0 + 1 << endl;
        }
        else if (n % 4 == 3)
        {
            // if (n > 4)
            // {
            cout << x0 + (n / 4) * 4 + 4 << endl;
            // }
            // else
            // {
            //     cout << x0 + 4 << endl;
            // }
        }
    }
    else
    {
        if (n % 4 == 0)
            cout << x0 << endl;
        else if (n % 4 == 1)
            cout << x0 + (n / 4) * 4 + 1 << endl;
        else if (n % 4 == 2)
            cout << x0 - 1 << endl;
        else if (n % 4 == 3)
        {
            // cout<<n/4<<endl;
            // cout<<(n/4)*4<<endl;
            cout << x0 - (n / 4) * 4 - 4 << endl;
        }
    }
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