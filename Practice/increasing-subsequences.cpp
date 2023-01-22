class Solution
{
public:
    void dfs(int idx, vector<int> &nums, vector<int> &sub, vector<vector<int>> &res)
    {
        if (sub.size() > 1)
            res.push_back(sub);
        unordered_set<int> St;
        for (int i = idx; i < nums.size(); i++)
        {
            // if present number bigger than what is in sub
            // if number has already been added
            if ((!sub.empty() and sub.back() > nums[i]) or St.count(nums[i]))
                continue;
            St.insert(nums[i]);
            sub.push_back(nums[i]);
            dfs(i + 1, nums, sub, res);
            sub.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> sub;
        dfs(0, nums, sub, res);
        return res;
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int N = nums.size();
        set<vector<int>> res;
        for (int i = 0; i < (1 << N); i++)
        {
            vector<int> tmp;
            for (int j = 0; j < N; j++)
            {
                if (i & (1 << j))
                {
                    if (tmp.empty())
                        tmp.push_back(nums[j]);
                    else if (tmp.back() <= nums[j])
                        tmp.push_back(nums[j]);
                }
            }
            if (tmp.size() >= 2)
                res.insert(tmp);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};