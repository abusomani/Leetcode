class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> result;
        int N = nums.size();
        if (N == 0)
            return result;

        for (int i = 0; i < N; i += 2)
        {
            int freq = nums[i], val = nums[i + 1];
            while (freq--)
                result.push_back(val);
        }

        return result;
    }
};