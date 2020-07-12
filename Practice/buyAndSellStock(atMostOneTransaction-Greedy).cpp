class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int N = prices.size(), ans = 0, mn = INT_MAX;
        if (N == 0)
            return 0;
        mn = prices[0];
        for (int i = 1; i < N; i++)
        {
            if (prices[i] < mn)
                mn = prices[i];
            ans = max(ans, prices[i] - mn);
        }

        return ans;
    }
};