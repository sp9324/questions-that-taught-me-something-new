#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

/*
WHAT I LEARNT:
cyclic arrays are simple.
during the contest, i spent a LOT of time trying to prove my solution and also got stuck in the 
implementation for a while. since this is problem a, simple brute force would work (even iterating over the entire map)
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, -1);
        map<int, int> mp;
        int mx = 0; // Initialize maximum frequency to 0
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            mx = max(mx, mp[a[i]]); // Update maximum frequency
        }
        cout << n - mx << endl;
    }
    return 0;
}