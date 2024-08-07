#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>
#include <chrono>
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
the code takes 2.375e-05s time
the commented code takes 1.54795s
(per test case)
so it's better to avoid any kinds of loops whenever possible!
*/

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        // while (n > 0)
        // {
        //     int dig = n % 10;
        //     ans += dig;
        //     n /= 10;
        // }
        ans=(n / 10) + (n % 10);
        cout << ans << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << "s" << std::endl;
    return 0;
}
