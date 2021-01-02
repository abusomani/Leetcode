class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N);
        int l = 0, r = N-1, idx = N-1, val;
        while(l <= r) {
            if(abs(nums[l]) >= abs(nums[r]))
                val = nums[l++];
            else
                val = nums[r--];
            res[idx--] = val * val;
        }
        return res;
    }
};