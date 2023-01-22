class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int ans = 1, cnt = 1, N = nums.size();
        if (N <= 1)
            return N;
        for (int i = 1; i < N; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
                cnt = 1;
        }

        return ans;
    }
};