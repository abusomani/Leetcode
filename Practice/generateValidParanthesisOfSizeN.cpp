class Solution
{
public:
    vector<string> result;
    void generateParanthesis(int n, int open, int closed, string str)
    {
        if (str.size() == 2 * n and open == closed and open == n)
        {
            result.push_back(str);
            return;
        }
        if (open < n)
            generateParanthesis(n, open + 1, closed, str + '(');
        if (closed < open)
            generateParanthesis(n, open, closed + 1, str + ')');
    }
    vector<string> generateParenthesis(int n)
    {
        generateParanthesis(n, 0, 0, "");
        return result;
    }
};