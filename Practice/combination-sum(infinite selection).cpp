class Solution
{
private:
    vector<vector<int>> result;

public:
    void process(vector<int> &candidates, int pos, long target, long currSum, vector<int> &curr)
    {
        if (currSum == target)
        {
            result.push_back(curr);
            return;
        }
        if (pos == candidates.size())
            return;

        for (int i = pos; i < candidates.size(); i++)
        {
            if (candidates[i] + currSum <= target)
            {
                curr.push_back(candidates[i]);
                process(candidates, i, target, candidates[i] + currSum, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        process(candidates, 0, target, 0, tmp);
        return result;
    }
};