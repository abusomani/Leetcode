/*
Consider trust as a graph, all pairs are directed edge.
The point with in-degree - out-degree = N - 1 become the judge.
*/
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        int ans = -1;
        vector<int> Indegree(N + 1, 0);
        for (auto t : trust)
        {
            Indegree[t[0]]--;
            Indegree[t[1]]++;
        }
        for (int i = 1; i <= N; i++)
            if (Indegree[i] == N - 1)
                return i;

        return ans;
    }
};