class Solution
{
public:
    // Without double lengthing
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> V(N, -1);
        stack<int> St;
        // do this 2N times
        for (int i = 0; i < 2 * N; i++)
        {
            int present = nums[i % N];
            while (!St.empty() and nums[St.top()] < present)
            {
                V[St.top()] = present;
                St.pop();
            }
            // push only if i is less than N
            if (i < N)
                St.push(i);
        }
        return V;
    }
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> V;
        for (auto &n : nums)
            V.push_back(n);
        for (auto &n : nums)
            V.push_back(n);

        stack<int> St;
        for (int i = 0; i < V.size(); i++)
        {
            while (!St.empty() and V[St.top()] < V[i])
            {
                V[St.top()] = V[i];
                St.pop();
            }
            St.push(i);
        }
        while (!St.empty())
            V[St.top()] = -1, St.pop();

        return vector<int>(V.begin(), V.begin() + N);
    }
};