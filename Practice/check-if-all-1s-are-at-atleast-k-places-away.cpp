class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        k++;
        bool res = true;
        int N = nums.size(), last = -k;
        for(int i=0; i<N; i++) {
            if(nums[i] == 1) {
                if(i - last < k)
                    return false;
                last = i;
            }
        }
        return res;
    }
};