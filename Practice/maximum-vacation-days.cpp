class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> Mp;
    int dfs(vector<vector<int>> &flights, vector<vector<int>> &days,
            int weekNumber, int city, int &N, int &K)
    {
        if (Mp.count(city) and Mp[city].count(weekNumber))
            return Mp[city][weekNumber];

        // if last week, no more vacation days
        if (weekNumber == K)
            return Mp[city][weekNumber] = 0;

        // for each week start with 0 vacation days
        int maxvac = 0;
        for (int i = 0; i < N; i++)
        {
            // if there is a connecting flight to city i from present city, or if its the city itself
            // in both conditions, take the vacationDays[i][weekNumber] and recurse further from city i and weekNumber+1
            if (flights[city][i] == 1 or i == city)
            {
                // if i travel to this city i on week weekNumber
                int val = days[i][weekNumber] + dfs(flights, days, weekNumber + 1, i, N, K);
                maxvac = max(maxvac, val);
            }
        }
        return Mp[city][weekNumber] = maxvac;
    }
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days)
    {
        int N = flights.size(); // N cities
        int K = days[0].size(); // K weeks

        return dfs(flights, days, 0, 0, N, K);
    }
};