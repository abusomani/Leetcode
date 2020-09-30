class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i=0; i<N; i++)
        {
            while(nums[i] > 0 and nums[i] <= N and nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i=0; i<N; i++)
        {
            if(nums[i] != (i+1))
                return i+1;
        }
        return N+1;
    }
};