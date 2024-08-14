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
my original solution uses a map.
to get rid of this space, we use 2 pointers. it is a clever observation. imagine the occupied seats 
as an interval. the next passenger coming must be either max value in the interval+1 or max value 
in the interval-1.
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

        bool bad = false;
        int l = a[0], r = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] == l-1)
                l--;
            else if (a[i] == r+1)
                r++;
            else
            {
                bad = true;
                break;
            }
        }
        if (bad)
            cout << "no" << endl;
        else
            cout << "yes" << endl;


// MY ORIGINAL SOLUTION

        // unordered_map<int, int> mp;
        // mp[a[0]]++;
        // bool flag = false;
        // for (int i = 1; i < n; i++)
        // {
        //     mp[a[i]]++;
        //     if (mp[a[i] - 1] == 0 && mp[a[i] + 1] == 0)
        //     {
        //         flag = true;
        //         cout << "no" << endl;
        //         break;
        //     }
        // }
        // if (!flag)
        //     cout << "yes" << endl;
    }
    return 0;
}