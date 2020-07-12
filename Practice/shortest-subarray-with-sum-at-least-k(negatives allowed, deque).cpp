/*
More detailed on this, we always add at the LAST position
B[d.back] <- B[i] <- ... <- B[future id]
B[future id] - B[d.back()] >= k && B[d.back()] >= B[i]
B[future id] - B[i] >= k too

so no need to keep B[d.back()]
*/
typedef long long ll;
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int K)
    {
        int N = nums.size();
        deque<int> Dq;
        vector<ll> Prefix(N + 1, 0);
        for (int i = 0; i < N; i++)
            Prefix[i + 1] = Prefix[i] + nums[i];

        int res = N + 1; // impossible
        for (int i = 0; i <= N; i++)
        {
            while (!Dq.empty() and (Prefix[i] - Prefix[Dq.front()] >= K)) // if sum >= K can be formed
            {
                res = min(res, i - Dq.front());
                Dq.pop_front();
            }
            while (!Dq.empty() and Prefix[i] <= Prefix[Dq.back()]) // if present sum is less than end
                Dq.pop_back();
            Dq.push_back(i);
        }

        return res < N + 1 ? res : -1;
    }
};