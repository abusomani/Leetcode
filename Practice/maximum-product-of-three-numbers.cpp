class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        // greedy of largest three or lowest two and the biggest (two negatives and one positive)
        return max(nums[N-1] * nums[N-2] * nums[N-3], nums[0] * nums[1] * nums[N-1]);
    }
};