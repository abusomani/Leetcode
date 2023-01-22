class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> prefix;
        prefix.push_back(0);
        for (auto &num : nums)
            prefix.push_back(prefix.back() + num);

        for (int i = 0; i < N; i++)
        {
            if (prefix[i] == (prefix[N] - prefix[i + 1]))
                return i;
        }
        return -1;
    }
};