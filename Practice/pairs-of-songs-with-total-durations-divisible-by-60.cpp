class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int> rem;
        for(auto &t : time) {
            if(t % 60 == 0)
                ans += rem[t%60];
            t %= 60;
            ans += rem[60-t];
            rem[t]++;
        }
        return ans;
    }
};