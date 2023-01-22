class Solution
{
public:
    int missingElement1(vector<int> &nums, int k)
    {
        int expected = nums[0] + k;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > expected)
                return expected;
            else
                expected++;
        }
        return expected;
    }
    bool kMissing(vector<int> &nums, int num, int k)
    {
        int idx = upper_bound(nums.begin(), nums.end(), num) - nums.begin();
        int gap = num - nums[0] - idx;
        return gap >= k;
    }
    int missingElement(vector<int> &nums, int k)
    {
        int l = nums[0], r = INT_MAX;
        k--;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (kMissing(nums, mid, k))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};