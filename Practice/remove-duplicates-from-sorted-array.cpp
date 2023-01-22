class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int N = nums.size(), idx = 1;
        if (N == 0)
            return N;
        for (int i = 1; i < N; i++)
        {
            if (nums[i] != nums[i - 1])
                nums[idx++] = nums[i];
        }
        return idx;
    }
};