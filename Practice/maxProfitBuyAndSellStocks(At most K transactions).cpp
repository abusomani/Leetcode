class Solution
{
public:
    int quickSolve(vector<int> &prices)
    {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])
                ans += (prices[i] - prices[i - 1]);

        return ans;
    }
    int maxProfit(int K, vector<int> &prices)
    {
        if (2 * K >= prices.size())
            return quickSolve(prices);

        vector<int> hold(K + 1, INT_MIN);
        vector<int> release(K + 1, 0);

        for (auto price : prices)
        {
            for (int i = K; i >= 1; i--)
            {
                release[i] = max(release[i], hold[i] + price);
                hold[i] = max(hold[i], release[i - 1] - price);
            }
        }

        return release[K];
    }
};