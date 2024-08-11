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
glad to have got the solution exactly right during the contest!
getting to the root of the problem wa key. the sum shd be xc*k and yc*k-> figure out the easiest way to get this
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        if (k % 2 == 0)
        {
            int j = 1;
            for (int i = 0; i < k; i++)
            {
                if (i % 2 == 0)
                    cout << x - j << " " << y + j << endl;
                else
                    cout << x + j << " " << y - j << endl;
                if (i % 2 != 0)
                    j++;
            }
        }
        else
        {
            int j = 1;
            for (int i = 0; i < k - 1; i++)
            {
                if (i % 2 == 0)
                    cout << x - j << " " << y + j << endl;
                else
                    cout << x + j << " " << y - j << endl;
                if (i % 2 != 0)
                    j++;
            }
            cout << x << " " << y << endl;
            // cout << endl;
        }
    }
    return 0;
}