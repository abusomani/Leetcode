class Solution
{
public:
    unordered_map<int, unordered_map<int, bool>> dp;
    bool dfs(string s, int sIdx, string t, int tIdx)
    {
        if (sIdx == 0)
            return dp[sIdx][tIdx] = true;
        if (tIdx == 0)
            return dp[sIdx][tIdx] = false;
        if (dp.count(sIdx) and dp[sIdx].count(tIdx))
            return dp[sIdx][tIdx];
        if (s[sIdx - 1] != t[tIdx - 1])
            return dp[sIdx][tIdx] = dfs(s, sIdx, t, tIdx - 1);
        else
            return dp[sIdx][tIdx] = dfs(s, sIdx - 1, t, tIdx - 1) or dfs(s, sIdx, t, tIdx - 1);
    }
    bool isSubsequence(string s, string t)
    {
        int N = s.size(), M = t.size();
        return dfs(s, N, t, M);
    }
    bool isSubsequenceEfficient(string s, string t)
    {
        int N = s.size(), M = t.size();
        int sIdx = 0;
        for (auto &c : t)
        {
            if (c == s[sIdx])
                sIdx++;
        }
        return sIdx == N;
    }
};