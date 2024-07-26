// linear time, constant space
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int mx=*max_element(nums.begin(), nums.end());
        int mn=*min_element(nums.begin(), nums.end());
        int n=nums.size(), mod=1000000007;
        long long su=accumulate(nums.begin(), nums.end(), 0LL);
        // mx-first + mx-second and so on gives the below formula
        long long totalGap=1LL*mx*n-sum;

        // case1: when using op1 is more optimal
        if(cost1*2<=cost2 || n<=2) return (totalGap*cost1)%MOD;

        // case2: better to apply op2 in pairs and THEN for the remaining, apply op1
        long long op1=max(0LL, (mx-mn)*2-totalGap);
        long long op2=totalGap-op1;
        long long res=(op1+op2%2)*cost1+op2/2*cost2;

        // case3: go beyond threshold (maybe increasing the highest gap could give a better answer)
        totalGap+=op1/(n-2)*n;
        op1 %= n - 2;
        op2 = totalGap - op1;
        res = min(res, (op1 + op2 % 2) * cost1 + op2 / 2 * cost2);

        // there may be op1 within n-2 also, so we need to check
        // case4: increase threshold twice (to be able to create more pairs for op2)
        for (int i = 0; i < 2; i++)
            {
                totalGap += n;
                res = min(res, totalGap % 2 * cost1 + totalGap / 2 * c2);
            }

                return res % mod;
     }
};