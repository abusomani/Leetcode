class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxEnd = 0, N = nums.size(), end = 0;
        for (int i = 0; i < N - 1; i++)
        {
            maxEnd = max(maxEnd, nums[i] + i);
            if (i == end)
            {
                end = max(end, maxEnd);
            }
        }
        return (end >= (N - 1));
    }
};