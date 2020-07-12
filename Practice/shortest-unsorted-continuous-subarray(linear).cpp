/*
Logic is to :
1. scan from left for first mismatch of sorted order, say left
2. scan from right for first mismatch of sorted order say right

Between this [left,right] subarray we need to find the minimum and maximum, to see where they belong to
Start traversing left to see where the minimum number needs to go (Insertion sort kind of logic)
Start traversing right to see where the maximum number needs to go
There is the answer.
*/
class Solution {
public:
    //[2, 3, 7, 8, 1, 5, 6]
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1]) ++left;
        if (left == n - 1) return 0; // return 0 if already sorted.
        // Or we know the array is unsorted
        // So, it's no need to judge right > 0
        while (/*right > 0 && */nums[right] >= nums[right - 1]) --right;

        int rmin = INT_MAX, lmax = INT_MIN;
        for (int i = left; i <= right; ++i) {
            lmax = max(lmax,nums[i]);
            rmin = min(rmin,nums[i]);
        }
        while (left >= 0 && nums[left] > rmin) --left;
        while (right < n && nums[right] < lmax) ++right;
        return right - left - 1;
    }
};