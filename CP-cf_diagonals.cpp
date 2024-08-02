#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>

using namespace std;

int solve(int n, int k)
{
    if (k == 0)
        return 0;
    if (k <= n)
        return 1;

    int cnt = 1;
    k -= n;
    n--;
    while (n > 0 && k > 0)
    {
        if (k >= 2 * n)
        {
            // both diagonals
            k -= 2 * n;
            n--;
            cnt += 2;
        }
        else if (k >= n)
        {
            // only one diagonal
            k -= n;
            cnt++;
            n--;
        }
        else // even less than n
        {
            // remaining chips can be placed on one diagonal
            cnt++;
            break;
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = solve(n, k);
        cout << ans << endl;
    }
    return 0;
}