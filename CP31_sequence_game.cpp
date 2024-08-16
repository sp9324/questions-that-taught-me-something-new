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
1. read constraints properly
2. dry run on ALL different test cases that you can think of even if solution may seem correct there may be something 
that the code is unable to handle. this can only be debugged by dry running
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<int> a;
        a.push_back(b[0]);
        for (int i = 1; i < n; i++)
        {
            if (b[i] >= a.back())
            {
                a.push_back(b[i]);
            }
            else
            {
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
        }

        cout << a.size() << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}