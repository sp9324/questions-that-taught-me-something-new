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
don't immediately think of a particular algo (like dp, backtracking etc) ->especially for 
problems A and B in cp. they can usually be done by figuring out a simple pattern and are definitely solvable
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        cout << min(n, k) * min(m, k) << endl;
    }
    return 0;
}