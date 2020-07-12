class Solution
{
public:
    int find_rotate_index(vector<int> &nums, int left, int right)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }

    int findMin(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
            return -1;
        if (N == 1)
            return nums[0];

        return nums[find_rotate_index(nums, 0, N - 1)];
    }
};