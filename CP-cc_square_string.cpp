#include <iostream>
#include <vector>
#define MOD 1000000007
#define N 500001

using namespace std;

int main() {
    // Initialize the dp array with zeros
    vector<long long> dp(N, 0);

    // Fill dp array with increments based on discovered formula
    for (int i = 1; i < N; ++i) {
        if (i < 5) {
            long long a = 2;
            long long s = 0;
            long long p = 1;
            // Compute 2^i % MOD
            for (int j = 0; j < i; ++j) {
                p = (p * 2) % MOD;
            }
            // Calculate s based on the discovered formula
            while (a <= i) {
                s += (p / (1LL << a)) * ((a - 1) * (a - 1));
                a++;
            }
            dp[i] = s % MOD;
        } else {
            // For i >= 5, use the formula dp[i] = 2 * dp[i - 1] + (i - 1)^2
            dp[i] = (2 * dp[i - 1]) % MOD;
            dp[i] = (dp[i] + ((long long)(i - 1) * (i - 1)) % MOD) % MOD;
        }
    }

    // Modify dp array by adding increments and doubling
    for (int i = 1; i < N; ++i) {
        // Get the previous dp value
        long long ans = dp[i - 1];
        // Add the previous dp value to the current dp value
        dp[i] = (dp[i] + ans) % MOD;
        // Double the current dp value
        dp[i] = (dp[i] * 2) % MOD;
    }

    // Handle multiple test cases
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // Output the result for the given n
        cout << dp[n] << endl;
    }

    return 0;
}
