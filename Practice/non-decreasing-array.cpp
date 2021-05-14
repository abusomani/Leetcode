class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int cnt = 0, N = nums.size();
        for (int i = 1; i < N; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                cnt++;
                /*
                    if we change nums[i] = nums[i-1] then nums[i+1] >= nums[i-1]
                    else if we change nums[i-1] = nums[i] then nums[i] >= nums[i-2]
                */
                if (cnt > 1 or (i + 1 < N and nums[i + 1] < nums[i - 1] and i - 2 >= 0 and nums[i] < nums[i - 2]))
                    return false;
            }
        }
        return true;
    }
};