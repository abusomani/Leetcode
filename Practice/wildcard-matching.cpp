class Solution
{
private:
    unordered_map<int, unordered_map<int, bool>> cache;

public:
    string cleanup(string p)
    {
        string res = "#";
        for (auto &c : p)
        {
            if (c == '*' and res.back() != '*')
                res.push_back(c);
            else if (c != '*')
                res.push_back(c);
        }
        return res.substr(1);
    }
    bool dfs(string &s, int sIdx, string &p, int pIdx)
    {
        if (cache.count(pIdx) and cache[pIdx].count(sIdx))
            return cache[pIdx][sIdx];

        if (pIdx == p.size())
            return cache[pIdx][sIdx] = sIdx == s.size();

        bool possible = false;
        // either * matches to empty string, or match to present character only if sIdx < s.size
        if (p[pIdx] == '*')
            possible |= dfs(s, sIdx, p, pIdx + 1) or (sIdx < s.size() and dfs(s, sIdx + 1, p, pIdx));
        else
            possible |= (sIdx < s.size() and (s[sIdx] == p[pIdx] or p[pIdx] == '?')) and dfs(s, sIdx + 1, p, pIdx + 1);

        return cache[pIdx][sIdx] = possible;
    }
    bool isMatch(string s, string p)
    {
        p = cleanup(p);
        return dfs(s, 0, p, 0);
    }
};