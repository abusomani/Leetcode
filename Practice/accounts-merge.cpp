class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int N = accounts.size();
        vector<int> ID(N, 0);
        for (int i = 0; i < N; i++)
            ID[i] = i;

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
                return;

            ID[parentB] = ID[parentA];
        };

        unordered_map<string, int> names;

        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (names.count(accounts[i][j]))
                    Union(i, names[accounts[i][j]]);
                names[accounts[i][j]] = i;
            }
        }
        unordered_map<int, set<string>> Mp;
        for (auto &name : names)
        {
            int parent = Find(name.second);
            Mp[parent].insert(name.first);
        }
        vector<vector<string>> res;
        for (auto &P : Mp)
        {
            string name = accounts[P.first][0];
            vector<string> tmp = {name};
            for (auto &s : P.second)
                tmp.push_back(s);
            res.push_back(tmp);
        }
        return res;
    }
};