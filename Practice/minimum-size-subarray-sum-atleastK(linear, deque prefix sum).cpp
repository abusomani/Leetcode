typedef long long ll;
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int N = nums.size();
        deque<int> Dq;
        vector<ll> Prefix(N + 1, 0);
        for (int i = 0; i < N; i++)
            Prefix[i + 1] = Prefix[i] + nums[i];

        int res = N + 1; // impossible
        for (int i = 0; i <= N; i++)
        {
            while (!Dq.empty() and (Prefix[i] - Prefix[Dq.front()] >= s))
            {
                res = min(res, i - Dq.front());
                Dq.pop_front();
            }
            Dq.push_back(i);
        }

        return res < N + 1 ? res : 0;
    }
};