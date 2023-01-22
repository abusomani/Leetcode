class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> Mp;
        int sum = 0, ans = 0, N = nums.size();
        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
            if (sum == k)
                ans++;
            if (Mp.count(sum - k))
                ans += Mp[sum - k];
            Mp[sum]++;
        }
        return ans;
    }
};