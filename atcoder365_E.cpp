#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
WHAT I LEARNT:
xor(Ar to Al)=prefixXor(r)^prefixXor(l-1) -> because same elements when xor'd, cancel each other out
*/

using lli = long long int;
using vi = vector<lli>;

const lli BT = 40;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli T = 1;
    // Uncomment the following line if you want to read multiple test cases
    // cin >> T;

    while (T--)
    {
        lli n;
        cin >> n;

        lli curXor = 0;
        vi prefXor(n + 1), a(n + 1);

        // Read input and calculate prefix XOR
        for (lli i = 1; i <= n; i++)
        {
            lli v;
            cin >> v;
            curXor ^= v;
            prefXor[i] = curXor;
            a[i] = v;
        }

        vi zeroCnt(BT), oneCnt(BT);

        // Count the number of 0s and 1s in each bit position for all prefix XORs
        for (const auto &y : prefXor)
        {
            for (lli j = 0; j < BT; j++)
            {
                if (y & (1LL << j))
                    oneCnt[j]++;
                else
                    zeroCnt[j]++;
            }
        }

        lli ans = 0;

        // Calculate the contribution of each bit position to the final answer
        for (lli j = 0; j < BT; j++)
        {
            const lli zero = zeroCnt[j], one = oneCnt[j];
            const lli pow2 = 1LL << j;
            /*For each bit position j, the number of pairs of prefix XOR
            values that have different bits at position j is given by
            zeroCnt[j] * oneCnt[j].*/
            ans += zero * one * pow2;
        }

        // Subtract the values of the array elements from the answer
        for (const auto &x : a)
            ans -= x;

        cout << ans << endl;
    }

    return 0;
}