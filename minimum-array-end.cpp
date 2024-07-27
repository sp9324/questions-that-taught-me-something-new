/*
learnt something new in bit manipulation!
this problem uses "BIT INTERLEAVING/INTERWEAVING"

points to note:
1. nums[0] will always be x itself
2. if there is a 1 at any position in x, we can't change it
3. cannot actually form the entire array because constraints are 1e8
4. observe the pattern is: the places to be filled in are just numbers: 0...n-1

constant time and space as we know max is 64 -> O(64)=O(1) time and space
*/

#define ll long long int

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        n--;
        vector<int> xBit(64, 0); //binary rep of x -> will finary have our answer
        vector<int> nBit(64, 0); 

        for (int i = 0; i < 32; i++)
        {
            xBit[i] = (x >> i) & 1; // set 1 if that position of x, i, has 1
            nBit[i] = (n >> i) & 1; // set 1 if that position of n, i, has 1
        }

        int i = 0, j = 0; //i for xbit, j for nbit
        while (i < 64) //the last number can be a 64 bit number
        {
            if (xBit[i] == 1)
            {
                i++;
                continue;
            }
            xBit[i++] = nBit[j++];
        }

        // convert binary rep of ans back to long long int
        ll ans = 0;
        for (int i = 0; i < 64; i++)
        {
            ans += xBit[i] * (1LL << i);
        }
        return ans;
    }
};