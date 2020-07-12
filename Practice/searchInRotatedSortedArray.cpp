class Solution
{
public:
    int find_rotate_index(vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    int binarySearch(vector<int> &nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int N = nums.size(), l = 0, r = N - 1;
        if (N == 0 or (N == 1 and nums[0] != target))
            return -1;

        int rotate_idx = find_rotate_index(nums, 0, N - 1);

        return max(binarySearch(nums, 0, rotate_idx - 1, target), binarySearch(nums, rotate_idx, N - 1, target));
    }
};