class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, n = nums.size();
        for (int num : nums)
            sum += abs(nums[n / 2] - num);
        return sum;
    }
};