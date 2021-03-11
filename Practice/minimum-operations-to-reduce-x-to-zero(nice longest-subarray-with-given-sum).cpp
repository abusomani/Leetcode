class Solution {
public:
    // Longest subarray with sum = Sum(nums) - X
    int minOperations(vector<int>& nums, int x) {
     int sum = 0;
        for (auto &num : nums) sum += num;
        int target = sum - x;
        
        // find the longest subarray that sums = target
        int presum = 0;
        int res = INT_MIN;
        unordered_map<int, int> Mp;
        Mp[0] = -1;
		
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            if (!Mp.count(presum)) 
                Mp[presum] =  i; // Always store smallest index
            if (Mp.count(presum - target)) {
                res = max(res, i - Mp[presum - target]);
            }
        }
        
        return res == INT_MIN  ? -1 : nums.size() - res;
    }
};