//linear time

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int>corrSquare;
        for(auto point : points) {
            auto maxCord=max(abs(point[0]), abs(point[1]));
            corrSquare.push_back(maxCord);
        }

        unordered_map<char, int> minSquare;
        int ignoreBigger=INT_MAX;
        for(auto i=0; i<corrSquare.size(); i++) {
            auto curSquare=corrSquare[i];
            if(minSquare.count(s[i])) {
                if (curSquare < minSquare[s[i]])
                {
                    ignoreBigger = min(ignoreBigger, minSquare[s[i]]);
                    minSquare[s[i]] = curSquare;
                }
                else
                {
                    ignoreBigger=min(ignoreBigger, curSquare);
                }
            } else {
                minSquare[s[i]]=curSquare;
            }
        }
        int ans=0;
        for(auto squareLen : corrSquare) if(squareLen<ignoreBigger) ans++;
        return ans;
    }
};