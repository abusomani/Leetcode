class Solution
{
private:
    vector<vector<int>> result;

public:
    void process(int k, long n, int pos, long currSum, vector<int> &curr)
    {
        if (currSum == n and k == 0)
        {
            result.push_back(curr);
            return;
        }
        if (k < 0)
            return;
        for (int i = pos; i <= 9; i++)
        {
            if (currSum + i <= n)
            {
                curr.push_back(i);
                process(k - 1, n, i + 1, currSum + i, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (k > n)
            return result;
        vector<int> tmp;
        process(k, n, 1, 0, tmp);
        return result;
    }
};