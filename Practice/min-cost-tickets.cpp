class Solution
{
private:
    int dp[366];

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        unordered_set<int> D(days.begin(), days.end());
        vector<pair<int, int>> C = {{1, costs[0]}, {7, costs[1]}, {30, costs[2]}};
        int sum = 0;
        for (int day = 1; day <= 365; day++)
        {
            if (!D.count(day))
            {
                dp[day] = dp[day - 1];
                continue;
            }
            int val = INT_MAX;
            for (int i = 0; i < 3; i++)
                val = min(val, C[i].second + (day >= C[i].first ? dp[day - C[i].first] : 0));
            dp[day] = val;
        }
        return dp[days.back()];
    }
};