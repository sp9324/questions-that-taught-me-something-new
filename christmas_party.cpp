#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define nl "\n"
const int MOD = 1000000007;

/*
STANDARD (OPTIMIZED) FORMULA FOR DERANGEMENTS: D(n)=(n-1)*(D(n-1)+D(n-2))

derivation:
https://medium.com/@harshittheone007/counting-derangements-b97ae9ec4582 (thru example)
*/

ll derangement(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    vector<ll> dp(n + 1); // 0 to n inclusive
    dp[0] = 1;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD; // mod at every position of dp array!!!
    }

    return dp[n];
}

void solveTest()
{
    int n;
    cin >> n;
    ll ans = derangement(n);
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solveTest();
    return 0;
}