class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int release1 = 0, release2 = 0;
        int hold1 = INT_MIN, hold2 = INT_MIN;

        for (auto price : prices)
        {
            release2 = max(release2, hold2 + price); // 2nd sell, implies second hold + price
            hold2 = max(hold2, release1 - price);    // 2nd buy, implies 1st stock's sell minus this price
            release1 = max(release1, hold1 + price); // sell then previous hold + current price
            hold1 = max(hold1, -price);              // buy then reduction
        }

        return release2;
    }
};