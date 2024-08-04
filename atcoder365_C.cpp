#include <iostream>
#include <vector>
#include <algorithm>

/*
WHAT I LEARNT:
binary search was supposed to be done on the values, not the indexes.
check for every value if it is a valid solution or not and accordingly update low and high.
*/

using namespace std;

#define ll long long

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n, 0);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll ele;
        cin >> ele;
        nums[i] = ele;
        sum += nums[i];
    }
    sort(nums.begin(), nums.end());

    if (sum <= m)
    {
        cout << "infinite" << endl;
        return 0;
    }

    ll x = -1;
    ll s = 0, e = nums[n - 1];
    while (s <= e)
    {
        ll mid = (s + e) / 2;
        ll total = 0;
        for (ll i = 0; i < n; i++)
        {
            total += min(nums[i], mid);
        }
        if (total <= m)
        {
            x = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << x << endl;
    return 0;
}