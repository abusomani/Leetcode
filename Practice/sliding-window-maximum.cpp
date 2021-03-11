class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> res;
        deque<int> Dq;
        for(int i=0; i<k; i++) {
            if(Dq.empty())
            {
                Dq.push_back(i);
                continue;
            }
            while(!Dq.empty() and nums[Dq.back()] < nums[i])
                Dq.pop_back();
            Dq.push_back(i);
        }
        for(int i=k; i<N; i++) {
            res.push_back(nums[Dq.front()]);
            while(!Dq.empty() and Dq.front() <= i-k)
                Dq.pop_front();
            while(!Dq.empty() and nums[Dq.back()] < nums[i])
                Dq.pop_back();
            Dq.push_back(i);
        }
        res.push_back(nums[Dq.front()]);
        return res;
    }
};