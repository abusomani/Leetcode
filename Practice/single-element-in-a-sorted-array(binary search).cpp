class Solution
{
public:
    //[1,1,2,3,3,4,4,8,8]
    //[0,1,2,3,4,5,6,7,8]
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (mid & 1)
            {
                // odd index equals previous index, implies single element is on right side
                if (nums[mid] == nums[mid - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
            {
                // even index and equals next index, implies single element is two index right atleast
                if (nums[mid] == nums[mid + 1])
                    l = mid + 2;
                else
                    r = mid;
            }
        }
        return nums[l];
    }

    // merging both conditions
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int idx = (mid & 1) ? mid - 1 : mid + 1;
            if (nums[mid] == nums[idx])
                l = (mid & 1) ? mid + 1 : mid + 2;
            else
                r = mid;
        }
        return nums[l];
    }
};