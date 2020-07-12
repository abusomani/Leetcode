vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
{
    ////////////////////////////////////////////////////////////////
    /* Union find: ID, size of group SZ, # of groups nG           */
    ////////////////////////////////////////////////////////////////
    vector<int> ID(m * n), SZ(m * n, 1);
    int mn = m * n, nG = mn;
    for (int i = 0; i < mn; ++i)
    {
        ID[i] = i;
    };

    auto find = [&](int a) {
        while (ID[a] != a)
        {
            a = ID[a];
        };
        return a;
    };

    /* a union find optimized with group size */
    auto Union = [&](int a, int b) {
        int ida = find(a), idb = find(b);
        if (ida == idb)
        {
            return nG;
        };

        if (SZ[ida] > SZ[idb])
        {
            ID[idb] = ida;
            SZ[ida] = SZ[ida] + SZ[idb];
        }
        else
        {
            ID[ida] = idb;
            SZ[idb] = SZ[ida] + SZ[idb];
        }
        return (--nG);
    };
    ////////////////////////////////////////////////////////////////

    /* set of location of lands */
    unordered_set<int> lands;
    vector<int> res;

    ////////////////////////////////////////////////////////////////
    /* add land one by one                                        */
    ////////////////////////////////////////////////////////////////
    constexpr int dirs[] = {0, +1, 0, -1, 0};
    for (auto &p : positions)
    {
        int id1 = p[0] * n + p[1]; // (x,y) in array of size [M,N] implies (N * x + y)
        lands.insert(id1);

        for (int d = 0; d < 4; ++d)
        {
            int x = p[0] + dirs[d], y = p[1] + dirs[d + 1];
            if ((x < 0) || (x >= m) || (y < 0) || (y >= n))
            {
                continue;
            };

            int id2 = x * n + y;
            if (lands.count(id2))
            {
                Union(id1, id2);
            }
        }

        res.push_back(nG + lands.size() - mn);
    }
    ////////////////////////////////////////////////////////////////

    return res;
}