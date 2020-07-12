class Solution
{
public:
    int lower(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size(), mid;
        while (start < end)
        {
            mid = (start + end) / 2;
            if (nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }

    int upper(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size(), mid;
        while (start < end)
        {
            mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = lower(nums, target), right = upper(nums, target);
        return (left == right) ? vector<int>{-1, -1} : vector<int>{left, right - 1};
    }
};