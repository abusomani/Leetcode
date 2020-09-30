/**
 * The idea is always keep an max-product-window less than K;
 * Every time add a new number on the right(j), reduce numbers on the left(i), until the subarray product fit less than k again, (subarray could be empty);
 * Each step introduces x new subarrays, where x is the size of the current window (j + 1 - i);
 * example:
 * for window (5, 2, 6), when 6 is introduced, it add 3 new subarray:
 *       (6)
 *    (2, 6)
 * (5, 2, 6)
 I think the trickiest part is why the number of newly introduced subarrays is j - i + 1.
Say now we have {1,2,3} and add {4} into it. Apparently, the new subarray introduced here are:
{1,2,3,4}, {2,3,4}, {3,4}, {4}, which is the number of elements in the new list.
If we also remove some at the left, say we we remove 1, then subarrays are:
{2,3,4}, {3,4}, {4}. It is easy to get the result is j - i + 1.
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int cnt = 0;
        int pro = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            pro *= nums[j];
            while (i <= j && pro >= k) {
                pro /= nums[i++];
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};