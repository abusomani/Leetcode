class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), [&](const vector<int> &a, const vector<int> &b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int sum = 0, N = costs.size() / 2;
        for (int i = 0; i < N; i++)
            sum += costs[i][0];
        for (int i = 0; i < N; i++)
            sum += costs[i + N][1];

        return sum;
    }
};