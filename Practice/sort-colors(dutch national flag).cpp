class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size(), i = 0, j = 0, k = N-1;
        while(j <= k)
        {
            if(nums[j] == 1)j++;
            else if(nums[j] == 0)swap(nums[i++], nums[j++]);
            else if(nums[j] == 2)swap(nums[k--], nums[j]);
        }
    }
};