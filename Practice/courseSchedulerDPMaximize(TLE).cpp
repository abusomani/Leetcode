class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        int N = courses.size();
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        vector<vector<int>> dp(N, vector<int>(courses[N - 1][1] + 1, -1));
        return maximize(dp, courses, 0, 0);
    }
    int maximize(vector<vector<int>> &dp, vector<vector<int>> &courses, int pos, int day)
    {
        if (pos == courses.size()) // cannot take any more course
            return 0;

        if (dp[pos][day] != -1)
            return dp[pos][day];

        int taken = 0;
        if (day + courses[pos][0] <= courses[pos][1]) // greedy
            taken = 1 + maximize(dp, courses, pos + 1, day + courses[pos][0]);
        int not_taken = maximize(dp, courses, pos + 1, day);
        dp[pos][day] = max(taken, not_taken);
        return dp[pos][day];
    }
};