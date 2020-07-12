class Solution
{
private:
    unordered_map<int, vector<int>> Mp;

public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            Mp[nums[i]].push_back(i);
    }

    int pick(int target)
    {
        int N = Mp[target].size();
        return Mp[target][rand() % N];
    }
};