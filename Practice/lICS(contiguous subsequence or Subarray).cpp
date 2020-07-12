class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int ans = 1, begin = 0, end = 0, N = nums.size();
        if (N == 0)
            return 0;
        for (int i = 1; i < N; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                end++;
            }
            else
            {
                begin = i;
                end = i;
            }
            ans = max(ans, end - begin + 1);
        }

        return ans;
    }
};