typedef long long ll;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        ll sm = 0, ans = 0, N = nums.size();
        unordered_map<ll, ll> Mp;
        Mp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            sm += nums[i];
            ans += Mp[sm - k];
            Mp[sm]++;
        }

        return ans;
    }
};