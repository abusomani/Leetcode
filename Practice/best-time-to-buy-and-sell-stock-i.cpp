class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, N = prices.size();
        if (N == 0)
            return 0;
        int mn = prices[0];
        for (int i = 1; i < N; i++)
        {
            mn = min(mn, prices[i]);
            ans = max(ans, prices[i] - mn);
        }
        return ans;
    }
};