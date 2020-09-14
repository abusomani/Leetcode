class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(int k, int n, vector<int> &V)
    {
        if(k == 0)
        {
            if(n == 0)
                ans.push_back(V);
        }
        else
        {
            for(int i=V.empty() ? 1 : V.back() + 1; i<=9; i++)
            {
                if(i <= n)
                {
                    V.push_back(i);
                    dfs(k-1, n-i, V);
                    V.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> V;
        dfs(k, n, V);
        return ans;
    }
};