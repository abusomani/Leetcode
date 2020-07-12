/*
Search in [1, 1, 1, 2, 2] for target 4, without the expression, you will get three identical combinations:
[1, 1, 2, 2] from index [0, 1, 3, 4] of the candidates;
[1, 1, 2, 2] from index [0, 2, 3, 4] of the candidates;
[1, 1, 2, 2] from index [1, 2, 3, 4] of the candidates.
*/
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
            if (i > pos and candidates[i] == candidates[i - 1]) // duplicate, explanation above
                continue;
            if (candidates[i] + currSum <= target)
            {
                curr.push_back(candidates[i]);

                process(candidates, i + 1, target, candidates[i] + currSum, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        process(candidates, 0, target, 0, tmp);
        return result;
    }
};