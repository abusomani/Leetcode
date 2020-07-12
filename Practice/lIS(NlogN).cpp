class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
            return 0;
        vector<int> res;
        for (int i = 0; i < N; i++)
        {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return res.size();
    }
};