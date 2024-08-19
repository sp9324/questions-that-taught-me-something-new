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
dont let the constraints and extra info daunt you. the problem only requires positive jumps.
When 𝑥
 is not divisible by 𝑘
, the grasshopper can reach 𝑥
 in just one jump.

Otherwise, you can show that two jumps are always enough. For example, jumps 1
 and 𝑥−1
. 1
 is not divisible by any 𝑘>1
. Also, 𝑥
 and 𝑥−1
 can't be divisible by any 𝑘>1
 at the same time.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;

        if (x < k)
        {
            cout << "1" << endl;
            cout << x << endl;
        }
        else if (x % k != 0)
        {
            cout << "1" << endl;
            cout << x << endl;
        }
        else
        {
            cout << "2" << endl;
            cout << x - 1 << " 1" << endl;
        }
    }
    return 0;
}