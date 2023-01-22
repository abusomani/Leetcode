//[[14,12,19,16,9],[13,14,15,8,11],[11,13,1]]
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<int> res;
        int N = nums.size();
        map<int, list<int>> Mp;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < nums[i].size(); j++)
                Mp[i + j].emplace_front(nums[i][j]);

        for (auto &row : Mp)
            for (auto &i : row.second)
                res.push_back(i);

        return res;
    }

    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int maxKey = 0;
        unordered_map<int, vector<int>> map;
        for (int r = nums.size() - 1; r >= 0; --r)
        { // The values from the bottom rows are the starting values of the diagonals.
            for (int c = 0; c < nums[r].size(); ++c)
            {
                map[r + c].push_back(nums[r][c]);
                maxKey = max(maxKey, r + c);
            }
        }
        vector<int> ans;
        for (int key = 0; key <= maxKey; ++key)
            for (int v : map[key])
                ans.push_back(v);
        return ans;
    }
};