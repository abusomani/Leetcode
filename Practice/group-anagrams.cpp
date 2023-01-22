class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> Mp;
        for (auto &c : strs)
            Mp[order(c)].push_back(c);
        for (auto &i : Mp)
            res.push_back(i.second);
        return res;
    }
    string order(string &s)
    {
        int cnt[26] = {0};
        for (auto &c : s)
            cnt[c - 'a']++;
        string res = "#";
        for (int i = 0; i < 26; i++)
            res += string(cnt[i], 'a' + i);
        return res;
    }
};