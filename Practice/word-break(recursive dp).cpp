class Solution
{
public:
    bool dfs(string s, int pos, unordered_set<string> &wordDict, vector<int> &dp)
    {
        if (s.size() == pos)
            return true;

        if (dp[pos] != -1)
            return (dp[pos] == 1);

        for (int len = pos + 1; len <= s.size(); len++)
        {
            string tmp = s.substr(pos, len - pos);
            if (wordDict.count(tmp) and dfs(s, len, wordDict, dp))
                return dp[pos] = 1;
        }
        return dp[pos] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.size() == 0 or wordDict.size() == 0)
        {
            return false;
        }
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return dfs(s, 0, dict, dp);
    }
};