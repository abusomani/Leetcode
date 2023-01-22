class Solution
{
public:
    void dfs(int open, int closed, int n, string curr, vector<string> &res)
    {
        if (curr.size() == 2 * n and open == closed)
        {
            res.push_back(curr);
            return;
        }
        else
        {
            if (open < n)
                dfs(open + 1, closed, n, curr + '(', res);
            if (closed < open)
                dfs(open, closed + 1, n, curr + ')', res);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n == 0)
            return res;
        dfs(0, 0, n, "", res);
        return res;
    }
};