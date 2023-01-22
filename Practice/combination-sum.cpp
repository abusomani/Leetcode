class Solution
{
private:
    vector<vector<int>> result;

public:
    void dfs(vector<int> &candidates, int target, int idx, int curr, vector<int> &path)
    {
        if (curr == target)
        {
            result.push_back(path);
            return;
        }
        else
        {
            for (int i = idx; i < candidates.size(); i++)
            {
                if (candidates[i] + curr <= target)
                {
                    path.push_back(candidates[i]);
                    dfs(candidates, target, i, curr + candidates[i], path);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> path;
        dfs(candidates, target, 0, 0, path);
        return result;
    }
};