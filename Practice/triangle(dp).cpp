class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int M = triangle.back().size(), N = triangle.size();
        vector<int> dp(M, INT_MAX);
        dp[0] = triangle[0][0];
        for(int i=1; i<N; i++){
            vector<int> tmp(M, INT_MAX);
            tmp[0] = triangle[i][0] + dp[0];
            for(int j=1; j<triangle[i].size(); j++)
                tmp[j] = triangle[i][j] + min(dp[j], dp[j-1]);
            dp = tmp;
        }
        int res = INT_MAX;
        for(auto c: dp)
            res = min(res, c);
        return res;
    }
};