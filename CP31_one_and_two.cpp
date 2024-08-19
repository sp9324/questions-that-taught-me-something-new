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
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
i could have done it without prefix sum, but that would have involved 2 traversals. one would have counted the
total number of twos and the other would get to half the number of twos.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        int pSum = 0;
        bool answered = false;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (ele == 2)
            {
                cnt++;
                pSum += 2;
                mp[pSum] = i;
            }
            if (i == n - 1 && (cnt % 2 != 0 || cnt == 0)) // if psum is 14
            {
                if (cnt == 0)
                {
                    cout << "1" << endl;
                    answered = true;
                }
                else if (cnt % 2 != 0)
                {
                    cout << "-1" << endl;
                    answered = true;
                }
            }
        }

        if (!answered)
        {
            cout << mp[pSum / 2] + 1 << endl;
        }
    }
    return 0;
}