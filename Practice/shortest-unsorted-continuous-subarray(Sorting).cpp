class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        int N = nums.size(), i = 0 , j = N-1;
        while(i < N and nums[i] == sorted[i])i++;
        while(j > i and nums[j] == sorted[j])j--;
        
        return (j-i+1);
    }
};