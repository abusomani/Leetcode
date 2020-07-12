// Reducing the problem to finding maximum length of subarray with sum equals K, where K = 0
// (by transforming 0 as -1, sum will be 0 if number of 0's equal 1's)

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int N = nums.size(), K = 0, sum = 0, ans = INT_MIN;
        unordered_map<int, int> Mp;
        for (int i = 0; i < N; i++)
            nums[i] = (nums[i] == 0) ? -1 : 1;

        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
            if (sum == 0)
                ans = max(ans, i + 1);
            if (Mp.count(sum))
                ans = max(ans, i - Mp[sum]);
            if (!Mp.count(sum))
                Mp[sum] = i;
        }

        return ans == INT_MIN ? 0 : ans;
    }
};