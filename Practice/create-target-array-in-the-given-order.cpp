class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        int N = nums.size();
        vector<int> target;
        for (int i = 0; i < N; i++)
        {
            target.emplace(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};