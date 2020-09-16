class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> V(m);
        for (int i = 0; i < m; i++)
            V[i] = i + 1;
        vector<int> res;
        for (auto &q : queries)
        {
            int idx = 0;
            while (idx < m and V[idx] != q)
                idx++;
            res.push_back(idx);
            V.erase(V.begin() + idx);
            V.insert(V.begin(), q);
        }
        return res;
    }
};