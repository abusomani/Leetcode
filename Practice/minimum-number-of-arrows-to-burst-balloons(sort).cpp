class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        int ans = 1, N = points.size();
        if(N == 0)return 0;
        int end = points[0][1];
        for(int i=1; i<N; i++) {
            if(points[i][0] > end) {
                ans++;
                end = points[i][1];
            }
        }
        return ans;
    }
};