typedef long long ll;
class Solution {
public:
    int compute(vector<int>& nums, ll target, ll idx, ll val, vector<vector<int>> &memo) {
        if(idx == nums.size()) 
            return val == target ? 1 : 0;
        
        if(memo[idx][val] != INT_MIN) 
            return memo[idx][val];
        
        return memo[idx][val] = 
            compute(nums, target, idx+1, val-nums[idx],memo) 
            + 
            compute(nums, target, idx+1, val+nums[idx],memo);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        ll sm = 0;
        for(auto num : nums)sm += num;
        
        vector<vector<int>>memo(nums.size(), vector<int>(1+sm*2));
        int N = nums.size();
        for(int i=0;i<N;i++)
            for(int j=0;j<(1+sm*2);j++)
                memo[i][j] = INT_MIN;
        
        return compute(nums,(ll)sm+S,0,sm,memo);
    }
};