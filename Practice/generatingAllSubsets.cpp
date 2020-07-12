class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int N = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < (1 << N); i++)
        {
            int j = i, idx = 0;
            vector<int> tmp;
            while (idx < N)
            {
                if (j & 1)
                    tmp.push_back(nums[idx]);
                idx++;
                j /= 2;
            }
            res.push_back(tmp);
        }

        return res;
    }
};