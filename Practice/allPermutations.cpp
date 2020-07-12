class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> V;
        
        sort(nums.begin(), nums.end());
        V.push_back(nums);
        while(nextPermutation(nums))
            V.push_back(nums);
        
        return V;
    }
    
    bool nextPermutation(vector<int>&nums) {
        int N = nums.size(), k , l;
        for(k = N-2;k>=0;k--)
            if(nums[k] < nums[k+1])break;
        if(k < 0)
            return false;
        else {
            for(l = N-1; l > k ; l--)
                if(nums[l] > nums[k])break;
            
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1, nums.end());
            return true;
        }
    }
};