class Solution
{
public:
    vector<int> numsSameConsecDiff(int N, int K)
    {
        if (N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> res;
        for (auto num = 1; num <= 9; ++num)
            dfs(num, N - 1, K, res);
        return res;
    }

private:
    void dfs(int num, int n, int K, vector<int> &res)
    {
        if (n == 0)
            res.push_back(num);
        else
        {
            auto dig = num % 10;
            if (dig + K <= 9)
                dfs(num * 10 + dig + K, n - 1, K, res);
            if (K != 0 && dig - K >= 0)
                dfs(num * 10 + dig - K, n - 1, K, res);
            // K != 0 is to avoid duplicates which will only occur in case of K = 0
        }
    }
};