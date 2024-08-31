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
using namespace std;

/*
WHAT I LEARNT:
don't try to simulate at first. try finding a pattern. there is almost always a more straightforward way around problems a and b!!!
*/

#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        int mx = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > mx)
                mx = a[i];
        }

        for (int i = 0; i < m; i++)
        {
            char c;
            int l, r;
            cin >> c >> l >> r;
            if (l <= mx && mx <= r)
            {
                if (c == '+')
                    mx++;
                else
                    mx--;
            }

            cout << mx << " ";
        }
        cout << endl;
    }
    return 0;
}
