#include <iostream>
#include <vector>
#include <algorithm>

/*
logic was pretty easy.. this question is the basically asking u whether something like bubble sort would work to sort an array. and it obviously would.
found out there's an stl function to check if a vector is_sorted
*/

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            nums[i] = ele;
        }
        if (k == 1 && !is_sorted(nums.begin(), nums.end()))
        {
            cout << "no" << endl;
        }
        else
            cout << "yes" << endl;
    }
    return 0;
}