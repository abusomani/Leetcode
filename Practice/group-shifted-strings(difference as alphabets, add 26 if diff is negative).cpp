class Solution
{
public:
    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        unordered_map<string, vector<string>> Mp;
        for (auto str : strings)
            Mp[order(str)].push_back(str);

        vector<vector<string>> ans;
        for (auto it : Mp)
            ans.push_back(it.second);

        return ans;
    }
    string order(string str)
    {
        int diff = 0;
        string res = string(1, str[0]); // default
        for (int i = 1; i < str.size(); i++)
        {
            diff = (str[i] - str[i - 1]);
            diff = (diff < 0) ? diff + 26 : diff;
            res += string(1, 'a' + diff);
        }
        return res.substr(1);
    }
};