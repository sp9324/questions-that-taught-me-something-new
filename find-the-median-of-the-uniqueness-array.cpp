/*
Algorithm:
Calculate the total number of subarrays size.
Initialize a to 1 and b to nums.size().
Perform binary search:
If a equals b, return a as the median.
If the difference between a and b is 1, calculate the number of subarrays with at most a distinct elements. If this count is greater than or equal to half of the total number of subarrays ((size + 1) / 2), return a. Otherwise, return b.
Calculate the mid-point mid between a and b.
Calculate the number of subarrays with at most mid distinct elements and compare it with half of the total number of subarrays.
If the count is equal to half of the total, return mid.
If the count is greater than half, adjust the search range to [a, mid].
If the count is less than half, adjust the search range to [mid + 1, b].
*/

class Solution
{
public:
    //  Function to count subarrays with more than k distinct elements
    // sliding window
    long long numsub(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        long long cnt = 0;
        long long i = 0, j = 0;
        long long res = 0;
        for (long long i = 0; i < nums.size(); i++)
        {
            while (j < nums.size() && cnt < k)
            {
                mp[nums[j]]++;
                if (mp[nums[j]] == 1)
                    cnt++;
                j++;
            }
            if (cnt == k)
            {
                res += (nums.size() - j + 1);
            }
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                cnt--;
        }
        return res;
    }

    int medianOfUniquenessArray(vector<int> &nums)
    {
        long long size = ((long long)nums.size() * (long long)(nums.size() + 1)) / (long long)2;
        long long a = 1, b = nums.size();

        // Binary search
        while (1)
        {
            if (a == b)
                return a;
            if (abs(a - b) == 1)
            {
                long long x1 = size - numsub(nums, a + 1);
                if (x1 >= (size + 1) / 2)
                    return a;
                return b;
            }
            long long mid = (a + b) / 2;
            long long x = size - numsub(nums, mid + 1);
            if (x == (size + 1) / 2)
                return mid;
            if (x > ((size + 1) / 2))
            {
                b = mid;
            }
            if (x < ((size + 1) / 2))
            {
                a = mid + 1;
            }
        }
        return 0;
    }
};