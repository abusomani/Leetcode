class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        const int N = (1 << nums.size());
        for (int i = 0; i < N; i++)
        {
            bitset<32> bit(i);
            vector<int> tmp;
            for (int j = 0; j < 32; j++)
                if (bit.test(j))
                    tmp.push_back(nums[j]);

            result.push_back(tmp);
        }
        return result;
    }
};