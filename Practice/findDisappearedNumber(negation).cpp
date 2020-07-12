class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> ans;
        for (int i = 0; i < N; i++)
        {
            int num = abs(nums[i]);
            int idx = num - 1;
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
        }

        for (int i = 0; i < N; i++)
            if (nums[i] > 0)
                ans.push_back(i + 1);

        return ans;
    }
};