class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, N = nums.size();
        for(int i=0;i<N;i++)ans ^= nums[i];
        
        return ans;
    }
};