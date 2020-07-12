class Solution
{
public:
    /*
    A tree has N-1 edges, this will have N edges
    */
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int N = edges.size(), groups = N;
        vector<int> ID(N, -1), SZ(N, 1);
        for (int i = 0; i < N; i++)
            ID[i] = i;

        auto find = [&](int a) {
            while (ID[a] != a)
            {
                ID[a] = ID[ID[a]];
                a = ID[a];
            }
            return a;
        };

        auto Union = [&](int a, int b) {
            int parentA = find(a), parentB = find(b);
            if (parentA == parentB)
                return groups;
            if (SZ[parentA] < SZ[parentB])
            {
                ID[parentA] = ID[parentB];
                SZ[parentB] += SZ[parentA];
            }
            else
            {
                ID[parentB] = ID[parentA];
                SZ[parentA] += SZ[parentB];
            }
            return (--groups);
        };

        vector<int> ans;
        for (auto edge : edges)
        {
            edge[0]--;
            edge[1]--;
            int parentA = find(edge[0]), parentB = find(edge[1]);
            if (parentA == parentB)
            {
                ans.push_back(edge[0] + 1);
                ans.push_back(edge[1] + 1);
            }
            else
                Union(edge[0], edge[1]);
        }
        return ans;
    }
};