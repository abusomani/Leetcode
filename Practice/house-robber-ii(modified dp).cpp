class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 1)
            return nums[0];
        if(N == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp1(N, INT_MIN), dp2(N, INT_MIN);
        // dp1 is at ith position max if started at 1
        // dp2 at ith position max if started at 2
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[0] = 0; // cannot take first item
        dp2[1] = nums[1]; // first item
        for(int i=2; i<N; i++) {
            if(i <= N-2)
            {
                dp1[i] = max(dp1[i-1], nums[i] + dp1[i-2]); // usual dp
                dp2[i] = max(dp2[i-1], nums[i] + dp2[i-2]);
            }
            else
            {
                dp1[i] = dp1[i-1]; // blindly from previous
                dp2[i] = max(dp2[i-1], nums[i] + dp2[i-2]);
            }
        }
        return max(dp1.back(), dp2.back()); // max of both worlds
    }
};