class Solution
{
public:
    // smallest element in the array
    int find_rotate_index(vector<int> &nums)
    {
        int N = nums.size(), l = 0, r = N - 1;
        if (nums[l] < nums[r])
            return 0;

        while (l < r)
        {
            int mid = l + ((r - l) >> 1);

            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    int bin_search(vector<int> &nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int N = nums.size();

        if (N == 0)
            return -1;
        if (N == 1)
            return nums[0] == target ? 0 : -1;

        int rot = find_rotate_index(nums);

        if (rot == 0)
            return bin_search(nums, 0, N - 1, target);

        if (target < nums[0])
            return bin_search(nums, rot, N - 1, target);

        return bin_search(nums, 0, rot, target);
    }
};