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

#define ll long long

/*
for every 3 attacks, health decreases by 5. when health is less than 5, we brute force the remaining.
so, the inner while loop will run 5 times in the worst case.
*/

int main()
{

    int n;
    cin >> n;
    vector<int> h(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    ll t = 0;
    for (int i = 0; i < n; i++)
    {
        ll f = h[i] / 5; // find how many times the health can be decreased by 5.
        t += f * 3; // that quotient multipy 3 is the attacks made.
        h[i] -= 5 * f; // then, actually decrease the health
        while (h[i] > 0) // brute force when less than 5
        {
            t++;
            if (t % 3 == 0)
                h[i] -= 3;
            else
                h[i]--;
        }
    }

    cout << t << endl;

    return 0;
}