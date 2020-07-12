class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int res = nums[0] + k, N = nums.size(); // real kth missing number
        for(int i=1;i<N;i++){
            if(nums[i] > res) {
                return res; 
            }
            else
                res += 1;
        }
        
        return res;
    }
};