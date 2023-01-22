class Solution
{
public:
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> Mp;
    bool dfs(string &A, int i, string &B, int j, string &C, int k)
    {
        if (Mp.count(i) and Mp[i].count(j) and Mp[i][j].count(k))
            return Mp[i][j][k];

        if (k == C.size())
            return Mp[i][j][k] = true;

        for (int pos = k; pos < C.size(); pos++)
        {
            if (i < A.size() and A[i] == C[pos] and dfs(A, i + 1, B, j, C, pos + 1))
                return Mp[i][j][k] = true;
            if (j < B.size() and B[j] == C[pos] and dfs(A, i, B, j + 1, C, pos + 1))
                return Mp[i][j][k] = true;
            else
                return Mp[i][j][k] = false;
        }
        return Mp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.size() != s1.size() + s2.size())
            return false;
        return dfs(s1, 0, s2, 0, s3, 0);
    }
};

// Time complexity => O(M * N)
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> Mp;
    bool dfs(string &A, int i, string &B, int j, string &C, int k)
    {
        if (Mp.count(i) and Mp[i].count(j))
            return Mp[i][j];

        if (i == A.size())
            return Mp[i][j] = B.substr(j) == C.substr(k);
        if (j == B.size())
            return Mp[i][j] = A.substr(i) == C.substr(k);

        bool isPossible = false;
        if ((A[i] == C[k] and dfs(A, i + 1, B, j, C, k + 1)) or (B[j] == C[k] and dfs(A, i, B, j + 1, C, k + 1)))
        {
            isPossible = true;
        }
        Mp[i][j] = isPossible;
        return isPossible;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.size() != s1.size() + s2.size())
            return false;
        return dfs(s1, 0, s2, 0, s3, 0);
    }
};