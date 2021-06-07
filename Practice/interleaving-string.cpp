class Solution {
private:
    unordered_map<int, unordered_map<int,int>> dp;
    bool dfs(string s1, string s2, string s3, int i, int j, int k){
        if(dp.count(i) and dp[i].count(j))
            return dp[i][j];
        if(i == s1.size())
            return s3.substr(k) == s2.substr(j);
        if(j == s2.size())
            return s3.substr(k) == s1.substr(i);
        bool isPossible = false;
        if((s1[i] == s3[k] and dfs(s1, s2, s3, i+1, j, k+1)) or
           (s2[j] == s3[k] and dfs(s1, s2, s3, i, j+1, k+1)))
            isPossible = true;
        return dp[i][j] = isPossible;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        return dfs(s1, s2, s3, 0, 0, 0);
    }
};