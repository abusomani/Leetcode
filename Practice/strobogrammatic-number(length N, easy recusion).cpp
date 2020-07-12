class Solution
{
public:
    vector<string> findStrobogrammatic(int n)
    {
        return dfs(n, n);
    }

    vector<string> dfs(int curr, int max)
    {
        if (curr == 0)
            return {""};
        if (curr == 1)
            return {"0", "1", "8"};
        vector<string> center = dfs(curr - 2, max);
        vector<string> tmp;
        for (int i = 0; i < center.size(); i++)
        {
            string s = center[i];
            if (curr != max)
                tmp.push_back("0" + s + "0");
            tmp.push_back("1" + s + "1");
            tmp.push_back("6" + s + "9");
            tmp.push_back("8" + s + "8");
            tmp.push_back("9" + s + "6");
        }

        return tmp;
    }
};