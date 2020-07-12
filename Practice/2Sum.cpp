class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> Mp;
        int N = nums.size();
        for(int i=0;i<N;i++)
        {
            if(Mp.find(target-nums[i]) != Mp.end())
                return vector<int>{Mp[target-nums[i]],i};
            Mp[nums[i]] = i;
        }
        return vector<int>{-1,-1};
    }
};