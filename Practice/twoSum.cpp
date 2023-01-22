class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> Mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Mp.count(target - nums[i]) and Mp[target - nums[i]] != i)
                return vector<int>({min(i, Mp[target - nums[i]]), max(i, Mp[target - nums[i]])});
            Mp[nums[i]] = i;
        }
        return vector<int>();
    }
};