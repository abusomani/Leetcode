class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int N = nums.size(), k, l;
        for (k = N - 2; k >= 0; k--) // find first number that is smaller than next number
            if (nums[k] < nums[k + 1])
                break;
        if (k < 0) // reverse sorted already
            reverse(nums.begin(), nums.end());
        else
        {
            for (l = N - 1; l > k; l--)
                if (nums[l] > nums[k])
                    break;
            swap(nums[l], nums[k]);
            reverse(nums.begin() + k + 1, nums.end()); // reverse the array after kth index
        }
    }
};