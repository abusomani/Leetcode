class Solution {
private:
    bool static compare(vector<int> &a, vector<int> &b){
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        int N = E.size(), res = 0;
        sort(E.begin(), E.end(), compare);
        vector<int> dp;
        for (auto e : E)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
            if (iter == dp.end())
                dp.push_back(e[1]);
            else if (e[1] < *iter)
                *iter = e[1];
        }
        return dp.size();
    }
};