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
my intuition:
we need to change the sum of every subarray (minus 1). i preferred incrementing over
decrementing as the placement may be such that another number causes the subarray sum
to be same as the original, which we don't want. so we increment. the sum will always
(mostly) be greater. we do this for consecutive elements so that it is impossible for any
subarray to have same sum. where we can't increment, put a 1. this can be proved by taking
variables a1, a2, a3, a4, a5 and checking all subarrays, as i did in the contest.




EDITORIAL 1:
Hint 1:
glad to have got it during the contest!
Sum of all elements will be equal in both permutations.
So no of such (𝑖,𝑗)
 is atleast 1.
Can you find a permutation 𝑄
 such that this count remains 1?

Hint 2
Set 𝑄𝑖=1
 if 𝑃𝑖=𝑁
,
Set 𝑄𝑖=1+𝑃𝑖
 if 𝑃𝑖<𝑁
, otherwise

I got it till step 2 but I was finding min and max (obvi, min==1 and max==n)-> silly me! :)

EDITORIAL 2:
Solution
We can always construct a solution such that the number of pairs (𝑖,𝑗)
 is 1
 where the only pair is (1,𝑛)
. There exists several constructions, such as rotating 𝑝
 once or increment all 𝑝𝑖
 (and 𝑝𝑖=𝑛
 turns into 𝑝𝑖=1
).

INTUITION:
Consider the former construction, where 𝑞=[𝑝2,𝑝3,...,𝑝𝑛,𝑝1]
. For an arbitrarily interval [𝑖,𝑗]
, 𝑝[𝑖..𝑗]
 and 𝑞[𝑖..𝑗]
 will have exactly 1
 element that's different, disregarding ordering. Since we have a permutation and all elements are distinct, the sum in the range will never be the same. The only exception is the entire array, of course.

Code (C++)
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n);
        for(int& i: p) cin >> i;
        rotate(p.begin(), p.begin() + 1, p.end()); // stl for rotation
        for(int i: p) cout << i << " ";
        cout << "\n";
    }
}
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
        int mx = INT_MIN;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == mx)
            {
                cout << mn << " ";
            }
            else
            {
                cout << a[i] + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}