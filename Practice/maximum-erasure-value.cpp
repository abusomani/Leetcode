class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, sm = 0, N = nums.size(), start = 0, end = 0, ctr=0;
        vector<int> prefix = {0};
        for(auto num: nums)prefix.push_back(num + prefix.back());
        unordered_map<int,int> Mp;
        while(end < N){
            if(Mp[nums[end++]]++ > 0)
                ctr++;
            while(ctr){
                // if greater than 1 then only reduce
                if(Mp[nums[start++]]-- > 1)
                    ctr--;
            }
            res = max(res, prefix[end] - prefix[start]);
        }
        return res;
    }
};