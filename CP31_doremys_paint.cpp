#include <iostream>
#include <unordered_map>
#include <cmath> // Include cmath for abs function

using namespace std;

/*
WHAT I LEARNT:
mp.end() is an iterator that points PAST the last element of a map, so accessing it gives an out of bouds error. 
also, make sure to simplify the problem and get to the root of it before actually starting on the solution.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        if (mp.size() == 1)
        {
            cout << "yes" << endl;
        }
        else if (mp.size() == 2)
        {
            auto it = mp.begin();
            int first = it->second;
            ++it;
            int second = it->second;

            if (abs(first - second) <= 1)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}