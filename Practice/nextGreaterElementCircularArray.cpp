class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        stack<int> St;
        vector<int> res(2*N,-1);
        for(int i=0;i<N;i++)nums.push_back(nums[i]);
        
        for(int i=0;i<2*N;i++) {
            while(!St.empty() and nums[i] > nums[St.top()]) {
                res[St.top()] = nums[i];
                St.pop();
            }
            St.push(i);
        }
        res.resize(N);
        return res;
    }
};