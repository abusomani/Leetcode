class Solution
{
public:
    bool isMutuallyExclusive(unordered_set<char> &L, unordered_set<char> &R)
    {
        for (auto &c : L)
            if (R.count(c))
                return false;
        return true;
    }
    vector<int> partitionLabels(string &S)
    {
        int N = S.size();
        vector<int> res, last(26, -1);
        for (int i = 0; i < N; i++)
            last[S[i] - 'a'] = i;

        int j = 0, partition = -1;
        for (int i = 0; i < N; i++)
        {
            j = max(j, last[S[i] - 'a']);
            if (i == j) // max of any characters last
                res.push_back(i - partition), partition = i;
        }
        return res;
    }
    vector<int> partitionLabelsMoreSpace(string &S)
    {
        int N = S.size();
        vector<int> psum, res;
        if (N == 0)
            return res;
        vector<unordered_set<char>> L(N + 1), R(N + 1);
        for (int i = 0; i < N; i++)
        {
            if (i)
                L[i] = L[i - 1];
            L[i].insert(S[i]);
        }
        L[N] = L[N - 1];
        for (int i = N - 1; i >= 0; i--)
        {
            if (i < N - 1)
                R[i] = R[i + 1];
            R[i].insert(S[i]);
        }

        for (int i = 0; i < N; i++)
            if (isMutuallyExclusive(L[i], R[i + 1]))
                psum.push_back(i + 1);
        for (int i = 0; i < psum.size(); i++)
        {
            if (i == 0)
                res.push_back(psum[i]);
            else
                res.push_back(psum[i] - psum[i - 1]);
        }
        return res;
    }
};