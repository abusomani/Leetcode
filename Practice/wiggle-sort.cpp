class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int N = nums.size();
        if (N <= 1)
            return;

        bool wiggle = true;
        for (int i = 0; i < N - 1; i++)
        {
            if (wiggle)
            {
                if (nums[i] > nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
            else
            {
                if (nums[i] < nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
            wiggle = !wiggle;
        }
    }
};