class Solution
{
public:
    unordered_set<int> set;
    bool dfs(int k, int pos, int destination)
    {
        if (pos > destination || !set.count(pos))
            return false;
        if (pos == destination)
            return true;
        for (int i = 1; i >= -1; i--) // simulating k+1, k and k-1
            if (k + i > 0 && dfs(k + i, pos + k + i, destination))
                return true;
        return false;
    }
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        if (n <= 1)
            return true;
        set.insert(0);
        for (int i = 1; i < n; i++)
        {
            set.insert(stones[i]);
            if (stones[i] - stones[i - 1] > i)
                return false; //key point !!
        }
        return dfs(1, 1, stones[n - 1]);
    }
};