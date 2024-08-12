#include <iostream>
#include <cmath>
using namespace std;

/*
geomtrical proof for this question is in editorial
*/

int t, n;
int x[100011], y[100011];
int xs, ys, xt, yt;

long long dis(int x1, int y1, int x2, int y2)
{
    return 1LL * (x2 - x1) * (x2 - x1) + 1LL * (y2 - y1) * (y2 - y1);
}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; ++i)
            cin >> x[i] >> y[i];

        cin >> xs >> ys >> xt >> yt;

        bool ok = true;

        for (int i = 1; i <= n; ++i)
        {
            if (dis(xt, yt, x[i], y[i]) <= dis(xt, yt, xs, ys))
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
