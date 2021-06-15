class Solution {
private:
    vector<vector<int>> dp;
    vector<int> prefix;
    int getSum(int start, int end){
        return prefix[end]-prefix[start];
    }
    // difference of choosn
    int dfs(int start, int end, int alice){
        if(start == end)
            return 0; // remaining score
        if(dp[start][end] != INT_MAX)
            return dp[start][end];
        int val = 0, 
            removeFirst = getSum(start+1, end+1),
            removeLast = getSum(start, end);
        if(alice){
            val = max(removeLast + dfs(start, end-1, !alice), 
                      removeFirst + dfs(start+1, end, !alice));
        } else {
             val = min(-removeLast + dfs(start, end-1, !alice), 
                      -removeFirst + dfs(start+1, end, !alice));
        }
        return dp[start][end] = val;
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int N = stones.size();
        dp.resize(N+1, vector<int>(N+1, INT_MAX));
        prefix = {0};
        for(auto s: stones)prefix.push_back(prefix.back() + s);
        return dfs(0, N-1, 1);
    }
};