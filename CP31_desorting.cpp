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
⌊(𝑦−𝑥)2⌋+1
could have used this directly
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int prev;
        cin >> prev;
        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            int next;
            cin >> next;
            minDiff = min(minDiff, next - prev);
            prev = next;
        }
        if (minDiff < 0)
            cout << "0" << endl;
        else if (minDiff <= 1)
            cout << "1" << endl;
        else
        {
            cout << minDiff / 2 + 1 << endl;
        }
    }
    return 0;
}