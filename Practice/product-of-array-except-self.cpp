class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int l = 1, r = 1, N = nums.size();
        vector<int> ans(N, 1);
        for (int i = 0; i < N; i++)
        {
            ans[i] *= l;
            ans[N - i - 1] *= r;
            l *= nums[i];
            r *= nums[N - i - 1];
        }
        return ans;
    }
};