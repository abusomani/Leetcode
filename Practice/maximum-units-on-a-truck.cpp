class Solution {
public:
    int maximumUnits(vector<vector<int>>& B, int T) {
        sort(B.begin(), B.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[1] > b[1];
        });
        int res = 0;
        for(auto p: B){
            res += min(T, p[0]) * p[1];
            T -= min(p[0], T);
        }
        return res;
    }
};