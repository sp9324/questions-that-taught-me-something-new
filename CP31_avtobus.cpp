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
#include <climits>
// #include <bits/stdc++.h>
using namespace std;

/*
WHAT I LEARNT:
a simpler way:-
Let the number of buses with two axles is 𝑥
 and the number of buses with three axles is 𝑦
. Then the equality 4𝑥+6𝑦=𝑛
 must be true. If 𝑛
 is odd, there is no answer, because the left part of the equality is always even. Now we can divide each part of the equality by two: 2𝑥+3𝑦=𝑛2
.

Let's maximize the number of buses. Then we should make 𝑥
 as large as possible. So, we will get 2+…+2+2=𝑛2
 if 𝑛2
 is even, and 2+…+2+3=𝑛2
 otherwise. In both cases the number of buses is ⌊𝑛2⌋
.

Now let's minimize the number of buses. So, we should make 𝑦
 as large is possible. We will get 3+…+3+3+3=𝑛2
 if 𝑛2
 is divisible by 3
, 3+…+3+3+2=𝑛2
 if 𝑛≡2(mod3)
, and 3+…+3+2+2=𝑛2
 if 𝑛≡1(mod3)
. In all cases the number of buses is ⌈𝑛3⌉
.

Also don't forget the case 𝑛=2
 — each bus has at least four wheels, so in this case there is no answer.

Time complexity: (1)
.
*/

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll mn = 0, mx = 0;
        ll ans = 0;

        if (n == 1 || n == 2 || n == 3 || n == 5)
            cout << "-1" << endl;
        else if (n == 4)
            cout << "1 1" << endl;
        else if (n == 6)
            cout << "1 1" << endl;
        else
        {
            // for min
            int rem = n % 6;
            if (rem == 1 || rem == 3 || rem == 5)
                ans = -1;
            else
            {
                if (rem == 0)
                {
                    mn += n / 6;
                }
                else if (rem == 2)
                {
                    mn += n / 6 - 1;
                    mn += (rem + 6) / 4;
                }
                else if (rem == 4)
                {
                    mn += n / 6;
                    mn += 1; // one bus with 4 wheels left
                }
            }

            // for max
            rem = n % 4;
            if (rem == 1 || rem == 3)
                ans = -1;
            else
            {
                if (rem == 0)
                {
                    mx += n / 4;
                }
                else if (rem == 2)
                {
                    mx += n / 4 - 1;
                    mx += (rem + 4) / 6;
                }
            }

            if (ans == -1)
                cout << ans << endl;
            else
                cout << mn << " " << mx << endl;
        }
    }
    return 0;
}