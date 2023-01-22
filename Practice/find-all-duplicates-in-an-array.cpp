class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (auto &num : nums)
        {
            int idx = abs(num);
            if (nums[idx - 1] < 0)
                result.push_back(idx);
            nums[idx - 1] = -1 * abs(nums[idx - 1]);
        }
        return result;
    }
};