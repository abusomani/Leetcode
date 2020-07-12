class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            while (!dq.empty() and nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
            while (!dq.empty() and dq.front() <= (i - k + 1))
                dq.pop_front(); // now [i-k+2,i+1] for next iteration
        }
        return ans;
    }
};