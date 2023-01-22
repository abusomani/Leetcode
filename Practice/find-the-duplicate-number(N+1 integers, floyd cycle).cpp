class Solution
{
public:
    // slow and fast pointer
    int findDuplicate(vector<int> &nums)
    {
        if (nums.size() < 1)
            return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};