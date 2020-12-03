class Solution {
public:
     bool canPartition(vector<int>& nums) {
        int sum =0 , n=nums.size();
        for(int i=0;i<n;i++)
            sum += nums[i];
        if(sum%2) return 0;  //if sum is odd it is not possible to divide it into exactly 2 sets
        sum/=2;
        // now find if a set exists with sum =sum/2;
        vector<bool> dp(sum +1 , false); 
        dp[0] = true; //sum 0 is always possible;
        for(auto i :nums) {
           for(int j=sum;j>=i;j--) 
               dp[j] = dp[j] || dp[j-i]; 
//we need to get to the sum of 'tsum'. We are now in k.. So it is possible to reach 'tsum' from k only if there exists a value of total-k;
        }
        return dp[sum];
    }
};

class Solution
{
private:
    vector<vector<int>> dp;

public:
    bool canPartition(vector<int> &nums)
    {
        int sm = 0;
        for (auto i : nums)
            sm += i;
        if (sm & 1)
            return false;
        sort(nums.begin(), nums.end());
        sm /= 2;
        if (nums.back() > sm)
            return false;
        dp.resize(nums.size(), vector<int>(sm + 1, -1));
        return dfs(nums, sm, nums.size() - 1);
    }
    bool dfs(vector<int> &nums, int sum, int idx)
    {
        if (sum == 0)
            return true;
        if (idx < 0)
            return false;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        if (nums[idx] > sum)
            return dfs(nums, sum, idx - 1);
        return dp[idx][sum] = dfs(nums, sum - nums[idx], idx - 1) or dfs(nums, sum, idx - 1);
    }
};