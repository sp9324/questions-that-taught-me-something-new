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
was trying to find a pattern but should have come up with better test cases.
also learnt about using continue statments to move to next test case instead of using lots of flags.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a1, an, b1, bn;
        vector<int> a(n, -1);
        vector<int> b(n, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        if (a == b)
        {
            cout << "Bob" << endl;
            continue;
        }
        reverse(a.begin(), a.end());
        if (a == b)
        {
            cout << "Bob" << endl;
            continue;
        }
        cout << "Alice" << endl;
    }
    return 0;
}