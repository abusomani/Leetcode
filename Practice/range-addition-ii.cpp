class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty())
            return m * n;
        int x = INT_MAX, y = INT_MAX;
        for(auto &o: ops)
            x = min(x, o[0]), y = min(y, o[1]);
        return x * y;
    }
};