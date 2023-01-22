class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int N = nums.size();
        int l = 0, r = N - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            bool isEven = !(mid & 1);
            if (isEven)
            {
                // then if till here is valid, this and next should be same, if yes go +2
                if (nums[mid] == nums[mid + 1])
                    l = mid + 2;
                else
                    r = mid;
            }
            else
            {
                // if till here is valid, this and prev should be same, if yes go +1
                if (nums[mid] == nums[mid - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return nums[l];
    }
};