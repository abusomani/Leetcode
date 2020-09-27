class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> Mp;
        for(auto &trip : trips) {
            Mp[trip[1]] += trip[0]; // came at this time
            Mp[trip[2]] -= trip[0]; // stops at this time
        }
        int curr = 0;
        for(auto &i : Mp) {
            curr += i.second;
            if(curr > capacity)return false;
        }
        return true;
    }
};