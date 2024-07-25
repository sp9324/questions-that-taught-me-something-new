/*
checking "if is valid" function is optimised. will take constant time at every check. so time is n*n*26, instead of n*n*n.
done using PREFIX SUM
*/ 

class Solution {
    
public:
    // declaring globally so don't have to pass param every time
    vector<int>dp;
    vector<vector<int>>prefSum;

    int solve(int i, string &s) {
        int n = s.length();
        if(i==-1) return 0;
        if (dp[i] != -1)
            return dp[i];

        int mini=n;
        for(int j=i; j>=0; j--) {
            bool isPossible=true;
            int ct=0;
            for(int k=0; k<26; k++) {
                int freq=prefSum[i][k]-(j-1>=0?prefSum[j-1][k]:0);
                if(ct!=0 && freq!=0 && freq!=ct) isPossible=false;
                ct=max(ct, freq);
            }
            if(!isPossible) continue;
            mini = min(mini, 1 + solve(j - 1, s));
    }
    return dp[i]=mini;
}

    int minimumSubstringsInPartition(string s) {
        int n=s.length();
        dp=vector<int>(n+1, -1);
        prefSum=vector<vector<int>>(n+1, vector<int>(26, 0));
        // imagine as a 2d array (cols->for all current prefsums, rows->each letter)
        prefSum[0][s[0]-'a']=1; 
        for(int i=1; i<n; i++) {
            prefSum[i][s[i]-'a']++;
            for(int j=0; j<26; j++) {
                prefSum[i][j]+=prefSum[i-1][j];
            }
        }

        return solve(n-1, s);
    }
};