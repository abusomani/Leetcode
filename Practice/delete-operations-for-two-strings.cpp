class Solution {
private:
    unordered_map<int, unordered_map<int,int>> dp;
    int dfs(string A, string B, int i, int j){
        if(i == 0)
            return j;
        if(j == 0)
            return i;
        if(dp.count(i) and dp[i].count(j))
            return dp[i][j];
        if(A[i-1] == B[j-1])
            return dp[i][j] = dfs(A, B, i-1, j-1);
        return dp[i][j] = 1+ min(dfs(A,B,i-1,j), dfs(A,B,i,j-1));
    }
public:
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, word1.size(), word2.size());
    }
};