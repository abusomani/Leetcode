class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> ans;
        for (int i = 0; i < N; i++)
        {
            int num = abs(nums[i]);
            int idx = num - 1;
            if (nums[idx] < 0)
            { // twice
                ans.push_back(num);
            }
            nums[idx] = -nums[idx];
        }

        return ans;
    }
};