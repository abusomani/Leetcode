class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result = "";
        int i = 0, N = strs.size();
        if (N == 0)
            return result;
        if (N == 1)
            return strs[0];

        while (true)
        {
            char ch = strs[0][i];
            for (int j = 1; j < N; j++)
            {
                if (i >= strs[j].size())
                {
                    return result;
                }
                if (strs[j][i] != ch)
                {
                    return result;
                }
            }
            result += ch;
            i++;
        }
        return result;
    }
};