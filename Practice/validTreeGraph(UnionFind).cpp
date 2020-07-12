class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        int N = edges.size(), groups = n;
        if (N != n - 1)
            return false;

        vector<int> ID(n, -1), SZ(n, 1);
        for (int i = 0; i < n; i++)
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

        for (auto edge : edges)
        {
            int parentA = find(edge[0]), parentB = find(edge[1]);
            if (parentA == parentB)
                return false;
            Union(edge[0], edge[1]);
        }

        return true;
    }
};