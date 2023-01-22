class Solution
{
public:
    unordered_map<int, int> cache;
    int dfs(int day, vector<int> &costs, unordered_set<int> &daySet)
    {
        if (cache.count(day))
            return cache[day];

        if (day >= 366)
            return cache[day] = 0;

        int val;
        if (!daySet.count(day))
            val = dfs(day + 1, costs, daySet);
        else
        {
            val = costs[0] + dfs(day + 1, costs, daySet);
            val = min(val, costs[1] + dfs(day + 7, costs, daySet));
            val = min(val, costs[2] + dfs(day + 30, costs, daySet));
        }
        return cache[day] = val;
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        unordered_set<int> daySet(days.begin(), days.end());
        // return dfs(1, costs, daySet);
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        for (int day = 1; day <= 365; day++)
        {
            if (!daySet.count(day))
            {
                dp[day] = dp[day - 1];
                continue;
            }
            else
            {
                int val = dp[day - 1] + costs[0];
                val = min(val, (day - 7) >= 0 ? dp[day - 7] + costs[1] : costs[1]);
                val = min(val, (day - 30) >= 0 ? dp[day - 30] + costs[2] : costs[2]);
                dp[day] = val;
            }
        }
        return dp[days.back()];
    }
};