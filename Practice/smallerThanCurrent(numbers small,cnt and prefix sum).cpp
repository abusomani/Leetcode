class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> cnt(101, 0);
        int N = nums.size();
        for (int num : nums)
            cnt[num]++;
        int sm = 0;
        for (int i = 1; i < 101; i++)
            cnt[i] += cnt[i - 1];

        for (int i = 0; i < N; i++)
            if (nums[i] != 0)
                nums[i] = cnt[nums[i] - 1];

        return nums;
    }
};