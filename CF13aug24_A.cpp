// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <utility>
// #include <iterator>
// #include <cmath>
// #include <limits>
#include <bits/stdc++.h>
using namespace std;

/*
what is learnt:
we can cin>>string directly, even if the given input is an integer
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // int a;
        // cin >> a;
        string s;
        cin >> s;
        // string s = to_string(a);
        if (s.substr(0, 2) == "10" && s[2] > '0' && stoi(s.substr(2, s.length() - 2)) >= 2)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}