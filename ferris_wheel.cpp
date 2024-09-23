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
// #include <iomanip>
// // #include <bits/stdc++.h>
// using namespace std;

/*
WHAT I LEARNT:
i used binary search
the logic of pairing heaviest and 2nd heaviest etc is difficult to implement because we'll have to traverse a lot to find a possible combination
so use 2 pointers (both ends of the sorted array)
*/

// #define ll long long
// #define nl "\n"
// #define all(x) (x).begin(), (x).end()
// #define inp(i, a, n)            \
//     for (int i = 0; i < n; i++) \
//         cin >> a[i];

// bool prd(map<int, int> &mpCopy, vector<int> &a, int mid, int x, int n)
// {
//     int i=0;
//     while(i<n)
//     {
//         cout << "a[i-1]: " << a[i - 1] << " mCopy[a[i-1]]: " << mpCopy[a[i - 1]] << nl;
//         // put 1st child
//         if (mpCopy[a[i - 1]] > 0)
//             mpCopy[a[i - 1]]--;
//         cout << "x - a[i - 1]: " << x - a[i - 1] << " mpCopy[x - a[i - 1]: " << mpCopy[x - a[i - 1]] << nl;
//         // put 2nd child
//         if (x - a[i - 1] >= 0)
//             if (mpCopy[x - a[i - 1]] > 0)
//                 mpCopy[x - a[i - 1]]--;
        
//         i++;
//     }
//     for (auto it : mpCopy)
//         if (it.second > 0)
//             return false;
//     return true;
// }

// void solveTest()
// {
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n, -1);
//     inp(i, a, n);
//     sort(a.rbegin(), a.rend());
//     map<int, int> mp;
//     for (int i = 0; i < n; i++)
//         mp[a[i]]++;
//     int l = 1, h = n;
//     int ans = -1;
//     // cout<<"n is: "<<n<<nl;
//     // cout<<"x is: "<<x<<nl;
//     while (l <= h)
//     {
//         int m = (h+l)/ 2;
//         cout << "m is " << m << nl;
//         map<int, int>mpCopy=mp;
//         if (prd(mpCopy, a, m, x, n))
//         {
//             ans = m;
//             h = m - 1;
//         }
//         else
//             l = m + 1;
//     }
//     cout << ans << nl;
//     return;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     // int tt;
//     // cin >> tt;
//     // while (tt--)
//     solveTest();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

// Variables used for the current problem
int n, x, p[maxn], i, j, ans;
// Keeps track of the number of children who have had their own gondola
bool have_gondola_yet[maxn];

void solve() {
	cin >> n >> x;
	for (int i = 0; i < n; ++i) cin >> p[i];
	sort(p, p + n);
	i = 0;
	j = n - 1;
	while (i < j) {
		if (p[i] + p[j] > x) {
			// If the total weight of two children exceeds x
			// Then we move to the lighter child.
			--j;
		} else {    // If it satisfies the condition.
			++ans;  // Increment the number of gondolas used
			// Mark that they have had their gondola
			have_gondola_yet[i] = have_gondola_yet[j] = true;
			++i;
			--j;  // Move to the next children.
		}
	}
	for (int i = 0; i < n; ++i) {
		// Calculate the number of children not having gondolas yet
		// to get the total number of gondolas needed for the problem.
		ans += have_gondola_yet[i] == false; // these are the ones that haven't been paired yet
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}