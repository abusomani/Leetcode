/*
Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/
class Solution
{
private:
    unordered_map<int, unordered_map<int, int>> dp; // cache

public:
    int process(vector<int> &nums, long target, int pos, long currSum)
    {
        if (dp.count(pos) and dp[pos].count(currSum))
            return dp[pos][currSum];

        if (currSum == target)
            return dp[pos][currSum] = 1;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] + currSum <= target)
                ans += process(nums, target, i, currSum + nums[i]);
        }
        return dp[pos][currSum] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return process(nums, target, 0, 0);
    }
};