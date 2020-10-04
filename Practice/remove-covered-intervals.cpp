class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int N = intervals.size(), ans = 0;
        vector<bool> dp(N, 1);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(i == j)continue;
                int a = intervals[i][0], b = intervals[i][1];
                int c = intervals[j][0], d = intervals[j][1];
                if(c <= a and b <= d)
                    dp[i] = 0;
            }
        }
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
    int removeCoveredIntervalsOptimal(vector<vector<int>> &intervals)
    {
        int N = intervals.size(), l = -1, r = -1, ans = 0;
        // [1,5], [1,4], [1,3], [2, 5]
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
            return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
        });
        for (auto &interval : intervals)
        {
            int a = interval[0], b = interval[1];
            if (b > r)
            {
                ans++;
            }
            r = max(r, b);
        }
        return ans;
    }
};