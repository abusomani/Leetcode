class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> ID(n, -1), SZ(n, 1); // ID for parent and size of each graph component
        int groups = n;                  // all are distinct groups

        for (int i = 0; i < n; i++)
            ID[i] = i; // root themselves

        // find parent of the node with path compression
        auto find = [&](int a) {
            while (ID[a] != a)
            {
                ID[a] = ID[ID[a]];
                a = ID[a];
            }
            return a;
        };

        // union of two components using find and SZ
        auto Union = [&](int a, int b) {
            int parentA = find(a), parentB = find(b);
            if (parentA == parentB)
                return groups;
            if (SZ[a] < SZ[b])
            {
                ID[parentA] = ID[parentB];
                SZ[b] += SZ[a];
            }
            else
            {
                ID[parentB] = ID[parentA];
                SZ[a] += SZ[b];
            }
            return (--groups); // one group got merged into another
        };

        for (auto edge : edges)
        {
            Union(edge[0], edge[1]);
        }

        return groups;
    }
};