class Solution
{
public:
    //Kadane's algorithm
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0], sum = nums[0], N = nums.size();
        for (int i = 1; i < N; i++)
            sum = max(nums[i], sum + nums[i]), ans = max(ans, sum);

        return ans;
    }
};
/*
The problem to find sum or maximum or minimum in an entire array or in a fixed-size sliding window could be solved by the dynamic programming (DP) approach in linear time.

There are two standard DP approaches suitable for arrays:

Constant space one. Move along the array and modify the array itself.

Linear space one. First move in the direction left->right, then in the direction right->left. Combine the results. Here is an example.
https://leetcode.com/articles/sliding-window-maximum/

*/