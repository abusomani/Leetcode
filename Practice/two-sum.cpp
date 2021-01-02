/*
    Find two elements sum equals target in unsorted array.
    Use unordered map for Linear time complexity.
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> Mp;
        vector<int> V;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Mp.count(target - nums[i]))
            {
                V.push_back(Mp[target - nums[i]]);
                V.push_back(i);
                return V;
            }
            Mp[nums[i]] = i;
        }
        return V;
    }
};