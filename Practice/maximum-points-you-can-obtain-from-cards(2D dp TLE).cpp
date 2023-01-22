class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<int> &V, int l, int r, int k){
        if(l > r or k == 0)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int sm = 0;
        sm = max(sm, V[l] + dfs(V, l+1, r, k-1));
        sm = max(sm, V[r] + dfs(V, l, r-1, k-1));
        return dp[l][r] = sm;
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        dp.resize(N, vector<int>(N, -1));
        return dfs(cardPoints, 0, N-1, k);
    }
};