class Solution
{
public:
    vector<string> findStrobogrammatic(int n)
    {
        return dfs(n, n);
    }
    vector<string> dfs(int n, int &N)
    {
        if (n == 0)
            return {""};
        if (n == 1)
            return {"0", "1", "8"};

        vector<string> strobo = dfs(n - 2, N);
        vector<string> newStrobo;
        for (auto &s : strobo)
        {
            if (n != N)
                newStrobo.push_back("0" + s + "0");
            newStrobo.push_back("1" + s + "1");
            newStrobo.push_back("6" + s + "9");
            newStrobo.push_back("8" + s + "8");
            newStrobo.push_back("9" + s + "6");
        }

        return newStrobo;
    }
};