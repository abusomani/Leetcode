class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0, buy, sell, profit = 0, N = prices.size() - 1; // trick is to make N = N-1 before hand.
        while (i < N)
        {
            while (i < N && prices[i + 1] <= prices[i]) // decreasing
                i++;
            buy = prices[i];

            while (i < N && prices[i + 1] > prices[i]) // increasing
                i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
    }
};