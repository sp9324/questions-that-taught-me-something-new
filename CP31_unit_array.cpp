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
formula was getting too complicated, so i used simulation.
it works because constraints are not too tight.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ones = 0, minusones = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (ele == 1)
                ones++;
            else
                minusones++;
        }

        int ops = 0;
        if (ones > minusones)
        {
            while (minusones % 2 != 0)
            {
                minusones--;
                ones++;
                ops++;
            }
        }
        else
        {
            while (ones < minusones || minusones % 2 != 0)
            {
                minusones--;
                ones++;
                ops++;
            }
        }

        cout << ops << endl;
    }
    return 0;
}