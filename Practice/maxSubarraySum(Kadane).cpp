class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, ans = INT_MIN, N = nums.size();
        for (int i = 0; i < N; i++)
        {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};