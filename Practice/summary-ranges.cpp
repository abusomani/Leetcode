class Solution {
public:
    void push(vector<string> &V, int start, int end) {
        if(start == end)
            V.push_back(to_string(start));
        else 
        {
            string interval = to_string(start) + "->" + to_string(end);
            V.push_back(interval);
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return {};
        vector<string> res;
        int start = nums[0], end = nums[0];
        for(int i=1; i<N; i++) {
            if(nums[i] == end + 1) {
                end = nums[i];
            } else {
                push(res, start, end);
                start = end = nums[i];
            }
        }
        push(res, start, end);
        return res;
    }
};