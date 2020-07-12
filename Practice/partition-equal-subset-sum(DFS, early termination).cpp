class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        const int N = nums.size();
        int sum = 0;
        for (auto &n : nums)
            sum += n;

        if (sum & 1)
            return false;
        sum /= 2;
        sort(nums.begin(), nums.end());
        if (nums[N - 1] > sum)
            return false;

        return helper(nums, sum, N - 1);
    }

    bool helper(vector<int> &nums, int sum, int idx) a
    {
        if (idx < 0)
            return false;
        if (nums[idx] > sum)
            return false;
        if (nums[idx] == sum)
            return true;

        return helper(nums, sum - nums[idx], idx - 1) or helper(nums, sum, idx - 1);
    }
};