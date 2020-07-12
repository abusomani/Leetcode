class Solution
{
public:
    int longestOnes(vector<int> &nums, int K)
    {
        deque<int> Dq;
        int ans = 0, N = nums.size();
        int cntZero = 0;
        for (int i = 0; i < N; i++)
        {
            if (nums[i] == 1)
                Dq.push_back(nums[i]);
            else
            {
                if (cntZero == K)
                {
                    Dq.push_back(0);
                    while (Dq.front() != 0) // ones
                        Dq.pop_front();
                    Dq.pop_front(); // one zero
                }
                else
                {
                    Dq.push_back(nums[i]);
                    cntZero++;
                }
            }

            ans = max(ans, (int)Dq.size());
        }

        return ans;
    }
};