class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int N = nums.size();
        int ans = INT_MIN;
        int localMax = 0;
        for (auto &num : nums)
        {
            localMax = max(num, localMax + num);
            ans = max(ans, localMax);
        }
        return ans;
    }
};