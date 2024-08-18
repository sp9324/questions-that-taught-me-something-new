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
        if(t<a) t+=24;
        if(b<a) b+=24;
        if(b<t) puts("Yes");
        else puts("No");

the above is an alternate solution that i wasn't able to fully implement
*/

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b < c && b != 0)
    {
        if (a < b || a > c)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else if (b < c && b == 0)
    {
        if (a > c)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else if (b > c) // works for both c==0 and not ==0
    {
        if (a > c && a < b)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}