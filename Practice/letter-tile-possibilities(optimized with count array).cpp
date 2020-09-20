class Solution {
private:
    int ans;
    int dp[26];
    void dfs(int len) {
        if(len == 0) 
        {
            ans++;
            return;
        }
        for(int i=0; i<26; i++)
        {
            if(dp[i])
            {
                dp[i]--;
                dfs(len-1);
                dp[i]++;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        ans = 0;
        int N = tiles.size();
        for(int i=0;i<26;i++)
            dp[i] = 0;
        for(auto &c : tiles)
            dp[c - 'A']++;
        for(int len=1; len <= N; len++) 
            dfs(len);
        return ans;
    }
};