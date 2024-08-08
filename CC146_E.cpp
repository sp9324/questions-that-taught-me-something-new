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
using while loops was making the solution hard to implement even though logic was correct. 
better to use prefix and suffx sums concepts
*/

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
        int ans = 0;
        vector<int> pref(n, 0);
        vector<int> suf(n, 0);

        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += a[i];
            pref[i] = curr;
        }
        curr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            curr += a[i];
            suf[i] = curr;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                if (pref[i] == suf[i])
                    ans += 2;
                else if (abs(pref[i] - suf[i])==1)
                    ans++;
            }
        }
        cout << ans << endl;
    }
}

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> a(n, -1);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         vector<int> temp;
//         for (int i = 0; i < n; i++)
//         {
//             while (a[i] == 0)
//             {
//                 temp.push_back(0);
//                 i++;
//             }
//         }
//         int ans = 0;
//         int i = 0;
//         int s1 = 0, s2 = 0;
//         int cnt = 0;
//         while (i < n && a[i] == 0)
//         {
//             i++;
//         }
//         while (i < n && a[i] != 0)
//         {
//             s1 += a[i];
//             i++;
//         }
//         while (i < n && a[i] == 0)
//         {
//             i++;
//             cnt++;
//         }
//         while (i < n && a[i] != 0)
//         {
//             s2 += a[i];
//             i++;
//         }

//         if (s1 == s2)
//         {
//             ans += cnt * 2;
//             s1 = s2;
//             s2 = 0;
//             cnt = 0;
//         }
//         else if (s1 == s2 + 1 || s2 == s1 + 1)
//         {
//             ans += cnt;
//             s1 = s2;
//             s2 = 0;
//             cnt = 0;
//         }

//         while (i < n)
//         {
//             while (i < n && a[i] == 0)
//             {
//                 i++;
//                 cnt++;
//                 cout << "before continue" << endl;
//                 // continue;
//                 cout << "after continue" << endl;
//             }
//             bool flag = false;
//             while (i < n && a[i] != 0)
//             {
//                 s2 += a[i];
//                 flag = true;
//             }
//             if (flag)
//             {
//                 if (s1 == s2)
//                 {
//                     ans += cnt * 2;
//                     s1 = s2;
//                     s2 = 0;
//                     cnt = 0;
//                 }
//                 else if (s1 == s2 + 1 || s2 == s1 + 1)
//                 {
//                     ans += cnt;
//                     s1 = s2;
//                     s2 = 0;
//                     cnt = 0;
//                 }
//             }
//         }

//         cout << ans << endl;
//     }
//     return 0;
// }

// void simulate(vector<int> &a, int start, int direction, int &destroyed)
// {
//     int n = a.size();
//     int pos = start;
//     while (pos >= 0 && pos < n)
//     {
//         if (a[pos] > 0)
//         {
//             a[pos]--;
//             if (a[pos] == 0)
//             {
//                 destroyed++;
//             }
//             direction = -direction; // Change direction
//         }
//         pos += direction;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }

//         int totalWalls = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (a[i] > 0)
//             {
//                 totalWalls++;
//             }
//         }

//         int ways = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (a[i] == 0)
//             {
//                 vector<int> temp = a;
//                 int destroyed = 0;
//                 simulate(temp, i, 1, destroyed); // Push right
//                 if (destroyed == totalWalls)
//                 {
//                     ways++;
//                 }

//                 temp = a;
//                 destroyed = 0;
//                 simulate(temp, i, -1, destroyed); // Push left
//                 if (destroyed == totalWalls)
//                 {
//                     ways++;
//                 }
//             }
//         }

//         cout << ways << endl;
//     }
//     return 0;
// }