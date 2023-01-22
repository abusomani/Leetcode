class Solution
{
public:
    bool areSimilar(string s, string t)
    {
        int N = s.size(), diff = 0;
        for (int i = 0; i < N; i++)
        {
            diff += (s[i] != t[i]);
            if (diff > 2)
                return false;
        }

        return diff == 0 or diff == 2;
    }
    int numSimilarGroups(vector<string> &A)
    {
        int N = A.size(), groups = N;
        vector<int> ID(N, 0), SZ(N, 0);
        for (int i = 0; i < N; i++)
            ID[i] = i, SZ[i] = 1;
        auto Find = [&](int a) {
            while (ID[a] != a)
            {
                ID[a] = ID[ID[a]];
                a = ID[a];
            }
            return a;
        };

        auto Union = [&](int a, int b) {
            int parentA = Find(a), parentB = Find(b);
            if (parentA == parentB)
                return groups;
            if (SZ[parentA] > SZ[parentB])
            {
                SZ[parentA] += SZ[parentB];
                ID[parentB] = ID[parentA];
            }
            else
            {
                SZ[parentB] += SZ[parentA];
                ID[parentA] = ID[parentB];
            }
            return (--groups);
        };

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (areSimilar(A[i], A[j]))
                    Union(i, j);

        return groups;
    }
};