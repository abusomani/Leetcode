class Solution
{
public:
    // Kind of making a hash
    // Logic: Difference between characters of shifted string would remain same
    // Represent the difference as characters themselves
    string order(string &S)
    {
        int diff = 0;
        string result = string(1, S[0]); // default, we will eliminate this
        for (int i = 1; i < S.size(); i++)
        {
            diff = S[i] - S[i - 1];
            diff = diff < 0 ? diff + 26 : diff;
            result += string(1, 'a' + diff);
        }
        return result.substr(1); // as for size N, there can be N-1 differences
    }
    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        unordered_map<string, vector<string>> Mp;
        for (auto &s : strings)
            Mp[order(s)].push_back(s);
        vector<vector<string>> result;
        for (auto &i : Mp)
            result.push_back(i.second);
        return result;
    }
};