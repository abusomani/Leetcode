class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int N = nums.size();
        if (N == 0)
            return -1;

        int l = 0, r = N - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);

            if (nums[mid] == target)
                return mid;

            if (nums[mid] == nums[l] and nums[mid] == nums[r])
                l++, r--;

            else if (nums[mid] >= nums[0])
            {
                if (target >= nums[0] and target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (target >= nums[mid] and target <= nums[N - 1])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};