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
Considering an array 𝑎
 of 𝑛
 (𝑛≥2
) positive integers, the following inequality holds for 2≤𝑖≤𝑛
:

gcd(𝑎1,𝑎2,⋯,𝑎𝑖)≤gcd(𝑎1,𝑎2)≤2
Therefore, when the prefix [𝑎1,𝑎2]
 of 𝑎
 is good, we can show that all the prefixes of 𝑎
 whose length is no less than 2
 are good, then 𝑎
 is beautiful. It is obvious that [𝑎1,𝑎2]
 is good when 𝑎
 is beautiful. So we get the conclusion that 𝑎
 is beautiful if and only if the prefix [𝑎1,𝑎2]
 is good.

We can check if there exist 𝑎𝑖,𝑎𝑗
 (𝑖≠𝑗
) such that gcd(𝑎𝑖,𝑎𝑗)≤2
. If so, we can move 𝑎𝑖,𝑎𝑗
 to the front of 𝑎
 to make it beautiful, then the answer is Yes. If not, the answer is No.

Time complexity: 𝑂(𝑛2log106)
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

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (gcd(a[i], a[j]) <= 2)
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}