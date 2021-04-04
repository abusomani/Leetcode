class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int res = -1;
        unordered_map<int, int>Mp;
        for(auto a: A)Mp[a]++;
        for(auto p: Mp)
            if(p.second == 1)
                res = max(res, p.first);
        return res;
    }
};