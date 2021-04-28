class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int,int> Mp;
        for(int i=0; i<N; i++){
            if(Mp.count(nums[i]) and i-Mp[nums[i]] <= k)
                return true;
            Mp[nums[i]] = i;
        }
        return false;
    }
};