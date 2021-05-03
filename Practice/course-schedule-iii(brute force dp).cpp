class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>> &courses, int idx, int lastDay){
        // cannot take any course if none left
        if(idx >= courses.size())
            return 0;
        if(dp[idx][lastDay] != -1)
            return dp[idx][lastDay];
        
        int val = 0;
        //take the course if possible. Else do not
        if(courses[idx][0] + lastDay <= courses[idx][1])
            val = 1 + dfs(courses, idx+1, courses[idx][0]+lastDay);
        val = max(val, dfs(courses, idx+1, lastDay));
        return dp[idx][lastDay] = val;
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        int N = courses.size(), Days = courses.back()[1];
        dp.resize(N, vector<int>(Days+1, -1));
        return dfs(courses, 0 , 0);
    }
};