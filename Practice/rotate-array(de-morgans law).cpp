class Solution {
public:
/*
    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
*/
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        if(N == 0)return;
        k %= N;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};