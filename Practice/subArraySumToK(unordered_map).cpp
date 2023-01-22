class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> Mp;
        int ans = 0, sum = 0;
        for (auto num : nums)
        {
            sum += num;   // prefix sum
            if (sum == k) // from index 0
                ans++;
            if (Mp.count(sum - k)) // internal subarrays, any prefixSum having (sum - k) as total
                ans += Mp[sum - k];
            Mp[sum]++;
        }
        return ans;
    }
};