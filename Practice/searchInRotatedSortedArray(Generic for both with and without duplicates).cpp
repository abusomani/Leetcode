/*
1) everytime check if targe == nums[mid], if so, we find it.
2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid]) 
  and if so, go to step 3), otherwise, the second half is in order,   go to step 4)
3) check if target in the range of [left, mid-1] (i.e. nums[left]<=target < nums[mid]), if so, do search in the first half, i.e. right = mid-1; otherwise, search in the second half left = mid+1;
4)  check if target in the range of [mid+1, right] (i.e. nums[mid]<target <= nums[right]), if so, do search in the second half, i.e. left = mid+1; otherwise search in the first half right = mid-1;
*/
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;

        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] == target)
                return true;

            // the only difference from the first one, trickly case, just update left and right
            if ((nums[left] == nums[mid]) && (nums[right] == nums[mid]))
            {
                ++left;
                --right;
            }

            else if (nums[left] <= nums[mid]) // in first half
            {
                if ((nums[left] <= target) && (nums[mid] > target)) // if target inside then right comes back
                    right = mid - 1;
                else // target lies in other half
                    left = mid + 1;
            }
            else
            {
                if ((nums[mid] < target) && (nums[right] >= target)) // inside this interval then left to mid+1
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};