class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int start = 0, end = -1, N = timeSeries.size(), idx = 0, ans = 0;
        while(idx < N) {
            int iS = timeSeries[idx], iE = iS + duration - 1;
            if(iS > end) {
                ans += duration;
                start = iS;
                end = iE;
            }
            else {
                ans += iE - end;
                end = iE;
                start = max(iS, start);
            }
            idx++;
        }
        return ans;
    }
};