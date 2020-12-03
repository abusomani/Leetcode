class Solution {
private:
    unordered_map<int,bool> dp;
    unordered_set<int> visited;
public:
    bool canReach(vector<int>& arr, int start) {
        if(start >= arr.size() or start < 0)
            return false;
        if(arr[start] == 0)
            return true;
        if(dp.count(start))
            return dp[start];
        visited.insert(start);
        bool valid = false;
        if(!visited.count(start + arr[start]))
            valid = valid or canReach(arr, start + arr[start]);
        if(!visited.count(start - arr[start]))
            valid = valid or canReach(arr, start - arr[start]);
        return dp[start] = valid;
    }
};