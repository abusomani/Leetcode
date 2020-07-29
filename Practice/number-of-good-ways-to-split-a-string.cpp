class Solution
{
public:
    int numSplits(string s)
    {
        int N = s.size(), ans = 0;
        if (N == 1)
            return ans;
        unordered_set<char> left, right;
        vector<int> L, R(N);

        for (int i = 0; i < N; i++)
        {
            left.insert(s[i]);
            L.push_back(left.size());
        }
        for (int i = N - 1; i >= 0; i--)
        {
            right.insert(s[i]);
            R[i] = right.size();
        }
        int len = 0;
        while (len <= N - 2)
        {
            if (L[len] == R[len + 1])
                ans++;
            len++;
        }
        return ans;
    }
};