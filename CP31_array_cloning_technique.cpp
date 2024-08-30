/*
was close, but couldnt implement the d=min(n-am, am) part. am is the number of max occurring elements in our
answer array and it goes on increasing.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n;
        cin >> n;
        map<int, int> q;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            ++q[x];
        }
        int am = 0;
        for (auto &[x, y] : q)
        {
            am = max(am, y);
        }
        int ans = 0;
        while (am < n)
        {
            int d = min(n - am, am);
            ans += 1 + d; // we add 1 for copying, and d for swapping d elements into our answer array.
            am += d; // because we now have d more elements of the max occurrence in our array.
        }
        cout << ans << '\n';
    }
    return 0;
}