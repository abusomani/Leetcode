class Solution {
private:
    bool next(vector<int> &nums) {
        int N = nums.size(), l = N-1, k = N-2;
        for(;k>=0;k--)
            if(nums[k] < nums[k+1])
                break;
        if(k < 0)
            return false;
        for(;l>k;l--)
            if(nums[l] > nums[k]) break;
        swap(nums[l], nums[k]);
        reverse(nums.begin()+k+1, nums.end());
        return true;
    }
public:
    void nextPermutation(vector<int>& nums) {
        if(next(nums))
            return;
        sort(nums.begin(), nums.end());
    }
};