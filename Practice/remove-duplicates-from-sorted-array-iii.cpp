class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size(), j = 1;
        if(N <= 2)
            return N;
        pair<int,int> P = {nums[0], 1}; // initial marker
        for(int i=1; i<N; i++) {
            if(nums[i] == P.first) {
                if(P.second < 2) { // write only if this is <= second instance.
                    nums[j++] = nums[i];
                }
                P.second++;
            } else { // Have to write.
                nums[j++] = nums[i];
                P.first = nums[i];
                P.second = 1;
            }
        }
        return j;
    }
};