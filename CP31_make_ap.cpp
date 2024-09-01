// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <utility>
// #include <iterator>
// #include <cmath>
// #include <limits>
// #include <numeric>
// #include <map>
// #include <climits>
// // #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         float a, b, c;
//         cin >> a >> b >> c;
//         if (2 * b == a + c)
//             cout << "yes" << endl;
//         else if (2 * b < a + c)
//         {
//             if (floor((a + c) / (2 * b)) == ceil((a + c) / (2 * b)))
//             {
//                 cout << "yes" << endl;
//             }
//             else
//                 cout << "no" << endl;
//         }
//         else if (2 * b > a + c)
//         {
//             if (floor((2 * b - c) / a) == ceil((2 * b - c) / a) || floor((2 * b - a) / c) == ceil((2 * b - a) / c))
//                 cout << "yes" << endl;
//             else
//                 cout << "no" << endl;
//         }
//         else
//             cout << "no" << endl;
//     }
//     return 0;
// }

/*
use modulo to check if the result is an integer when possible.
*/

#include <iostream>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        // Check if the numbers can form an AP
        if (2 * b == a + c)
        {
            cout << "yes" << endl;
        }
        else if ((a + c) % (2 * b) == 0)
        {
            cout << "yes" << endl;
        }
        else if ((2 * b - c) % a == 0 && (2 * b - c) / a > 0)
        {
            cout << "yes" << endl;
        }
        else if ((2 * b - a) % c == 0 && (2 * b - a) / c > 0)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}