class Solution {
public:
    bool wordBreak(string s, vector<string>& W) {
        int N = s.size();
        unordered_set<string> words(W.begin(), W.end());
        unordered_set<int> valid_sizes;
        for(auto &w : W)
            valid_sizes.insert((int)w.size());
        vector<vector<int>> dp(N+1);
        dp[N].push_back(INT_MAX);
        for(int i=N; i>=0; i--) {
            if(dp[i].empty())continue;
            
            for(auto &sz: valid_sizes) {
                if(i >= sz) {
                    string sub = s.substr(i-sz, sz);
                    if(words.count(sub)) {
                        dp[i-sz].push_back(sz);
                    }
                }
            }
            
        }
        return !dp[0].empty();
    }
};