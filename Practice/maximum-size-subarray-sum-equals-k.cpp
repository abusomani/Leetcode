class Solution
{
public:
    int maxSubArrayLen(vector<int> &nums, int k)
    {
        int maxLen = INT_MIN, sum = 0, N = nums.size();
        unordered_map<int, int> Mp;
        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
            if (sum == k) // starts from 0th index
                maxLen = max(maxLen, i + 1);
            if (Mp.count(sum - k))
                maxLen = max(maxLen, i - Mp[sum - k]); // number of elements from (Mp[sum-k]+1, .., i)
            if (!Mp.count(sum))
                Mp[sum] = i;
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};