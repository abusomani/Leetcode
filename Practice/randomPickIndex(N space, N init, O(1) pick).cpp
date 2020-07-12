class Solution
{
public:
    unordered_map<int, vector<int>> Mp;
    Solution(vector<int> &nums)
    {
        int N = nums.size();
        for (int i = 0; i < N; i++)
            Mp[nums[i]].push_back(i);
    }

    int pick(int target)
    {
        int size = (Mp[target]).size();
        int x = rand() % size;
        return Mp[target][x];
    }
};
