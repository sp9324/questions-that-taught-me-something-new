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
WHAT I LEARNT
one optimization could be replacing the odd and even values with 2 and 0 respectively so that we dont need to compute the modulo every time
my solution would be required if the fina array was asked, but they only need the number of ops.
*/

#define ll long long

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
        if (a.size() == 1)
            cout << "0" << endl;
        else
        {
            ll ops = 0;
            int i = 0, j = 0;
            while (j < n)
            {
                bool par = a[j] % 2;
                while (j<n && a[j] % 2 == par)
                {
                    j++;
                }
                if (j - i > 1)
                    ops += j - i - 1;
                i = j;
                par = a[j] % 2;
            }
            cout << ops << endl;
        }
    }
    return 0;
}