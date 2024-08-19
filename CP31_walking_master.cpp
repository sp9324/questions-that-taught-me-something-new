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
Hint 1: The value of 𝑏
 is always non-decreasing, and the value of 𝑎−𝑏
 is always non-increasing.

It is possible to move from (𝑎,𝑏)
 to (𝑐,𝑑)
 if and only if 𝑑≥𝑏
 and 𝑎−𝑏≥𝑐−𝑑
, since the value of 𝑏
 is always non-decreasing and the value of 𝑎−𝑏
 is always non-increasing.

If it is possible, the answer is (𝑑−𝑏)+((𝑎+𝑑−𝑏)−𝑐)
. One possible way is (𝑎,𝑏)→(𝑎+𝑑−𝑏,𝑑)→(𝑐,𝑑)
.

Another way to understand this: (𝑎,𝑏)→(𝑎+𝑑−𝑏,𝑑)→(𝑐,𝑑)
 is always a valid path if it is possible to move from (𝑎,𝑏)
 to (𝑐,𝑑)
. So first let 𝑎←𝑎+(𝑑−𝑏)
 and 𝑏←𝑑
, then the answer only depends on 𝑎
 and 𝑐

*/

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c && b == d)
        {
            cout << "0" << endl;
        }
        else if (d < b)
        {
            cout << "-1" << endl;
        }
        else if (d == b)
        {
            if (a < c)
            {
                cout << "-1" << endl;
            }
            else
            {
                cout << a - c << endl;
            }
        }
        else
        { // d>b
            if ((a + (d - b)) > c)
            {
                cout << (d - b) + (a + (d - b) - c) << endl;
            }
            else if ((a + (d - b)) == c)
            {
                cout << (d - b) << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}