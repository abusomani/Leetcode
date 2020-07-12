/*
Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]
*/
// Time Complexity => O(N * 4^N)
typedef long long ll;
class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }

    void dfs(string &s, int target, int pos, long cv, long pv, string r, vector<string> &res)
    {
        if (pos == s.size() and cv == target)
        {
            res.push_back(r);
            return;
        }

        for (int len = 1; len <= s.size() - pos; len++)
        {
            string t = s.substr(pos, len);
            if (len > 1 and t[0] == '0')
                continue; // starts with 0, invalid
            long num = stol(t);
            if (pos == 0)
            { // first time
                dfs(s, target, len, num, num, t, res);
                continue;
            }
            dfs(s, target, pos + len, cv + num, num, r + "+" + t, res);
            dfs(s, target, pos + len, cv - num, -num, r + "-" + t, res);
            dfs(s, target, pos + len, cv - pv + pv * num, pv * num, r + "*" + t, res);
        }
    }
};