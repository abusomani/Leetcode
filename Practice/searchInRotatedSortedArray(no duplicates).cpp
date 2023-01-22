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
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] >= nums[l])
            {
                if (target >= nums[l] and target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (target >= nums[mid] and target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};