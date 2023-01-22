class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        const int N = nums.size();
        int i = 0;
        for (auto &num : nums)
            if (num)
                swap(nums[i++], num);
    }
};