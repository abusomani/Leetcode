class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size() , l = 0, r = N-1;
        while(l < r)
        {
            int mid = l + ((r-l)>>1);
            if(nums[mid] > nums[r])
                l = mid+1;
            else if(nums[mid] < nums[r])
                r = mid;
            else
                r--;
        }
        
        return nums[l];
    }
};