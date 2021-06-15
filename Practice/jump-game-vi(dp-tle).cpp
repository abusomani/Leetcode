class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp(N, INT_MIN);
        dp[0] = nums[0];
        for(int i=1; i<N; i++){
            for(int j=i-1; j>= max(i-k,0); j--)
                dp[i] = max(dp[i], dp[j] + nums[i]);
        }
        return dp[N-1];
    }
};