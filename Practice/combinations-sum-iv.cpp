class Solution {
private:
    unordered_map<int, unordered_map<int,int>> dp;
public:
    int dfs(int T, int idx, vector<int> &nums){
        if(T == 0)
            return 1;
        if(idx == nums.size())
            return 0;
        if(dp.count(T) and dp[T].count(idx))
            return dp[T][idx];
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= T)
                res += dfs(T-nums[i], i, nums);
        }
        return dp[T][idx] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(target, 0, nums);
    }
};