class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> Mp;
        for(auto &num: nums){
            Mp[num]++;
            if(Mp[num-1])
                res = max(res, Mp[num]+Mp[num-1]);
            if(Mp[num+1])
                res = max(res, Mp[num]+Mp[num+1]);
        }
        return res;
    }
};