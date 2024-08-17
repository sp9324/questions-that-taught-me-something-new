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
finding a pattern is very important.
take examples of your own as sometimes the test cases given are not enough
also, an optimization could be made by one simple observation
the ans will be -1 only if all elements are the same. we don't need to construct b and c to check that. this could
be done to prevent TLE
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
        sort(a.rbegin(), a.rend());

        vector<int> c;
        vector<int> b;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[0])
            {
                c.push_back(a[i]);
            }
            else
            {
                b.push_back(a[i]);
            }
        }

        if (b.size() == 0 || c.size() == 0)
            cout << "-1" << endl;
        else
        {
            cout << b.size() << " " << c.size() << endl;
            for (int i = 0; i < b.size() - 1; i++)
                cout << b[i] << " ";
            cout << b[b.size() - 1] << endl;
            for (int i = 0; i < c.size() - 1; i++)
                cout << c[i] << " ";
            cout << c[c.size() - 1] << endl;
        }
    }
    return 0;
}