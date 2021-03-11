class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, N = nums.size(), l = 0, r = N-1;
        while(l < r) {
            int value = nums[l] + nums[r];
            if(value > k)
                r--;
            else if(value < k)
                l++;
            else {
                l++;
                r--;
                res++;
            }
        }
        return res;
    }
};