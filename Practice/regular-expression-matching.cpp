class Solution
{
public:
    unordered_map<int, unordered_map<int, bool>> Mp;
    bool dfs(string &s, int sIdx, string &p, int pIdx)
    {
        if (Mp.count(sIdx) and Mp[sIdx].count(pIdx))
            return Mp[sIdx][pIdx];
        if (pIdx == p.size())
            return Mp[sIdx][pIdx] = sIdx == s.size();

        // check for present character of both
        bool match = sIdx < s.size() and (s[sIdx] == p[pIdx] or p[pIdx] == '.');
        // either match to empty string, so present of sIdx will now be matched to pIdx + 2
        // else if we are matching, then its AND of (match and dfs(sIdx+1, pIdx))
        if (pIdx + 1 < p.size() and p[pIdx + 1] == '*')
            match = dfs(s, sIdx, p, pIdx + 2) or (match and dfs(s, sIdx + 1, p, pIdx));
        else
            match = match and dfs(s, sIdx + 1, p, pIdx + 1);
        return Mp[sIdx][pIdx] = match;
    }
    bool isMatch(string s, string p)
    {
        return dfs(s, 0, p, 0);
    }
};