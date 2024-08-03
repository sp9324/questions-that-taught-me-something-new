#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        int cnt = 0;
        bool done = false;
        for (int i = 0; i < 2; i++)
        {
            while (nums[i] <= nums[2] && cnt <= 5)
            {
                nums[i]++;
                cnt++;
                if (cnt == 5)
                {
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }

        if (done)
        {
            cout << nums[0] * nums[1] * nums[2] << endl;
        }
    }
    return 0;
}
