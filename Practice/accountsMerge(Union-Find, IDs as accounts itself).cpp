class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<int> ID(accounts.size(), 0);       // each account is its own parent
        unordered_map<string, int> EmailToParent; // each email belongs to which ID

        auto Find = [&](int a) {
            while (ID[a] != a)
            {
                ID[a] = ID[ID[a]]; // parent to grandparent
                a = ID[a];
            }
            return a;
        };

        auto Union = [&](int a, int b) {
            int parentA = Find(a), parentB = Find(b);
            ID[parentA] = ID[parentB];
        };

        for (int i = 0; i < accounts.size(); i++)
        {
            ID[i] = i; // set parent of itself
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++)
            {
                // union account i with EmailToParent[accounts[i][j]]
                if (EmailToParent.find(accounts[i][j]) != EmailToParent.end())
                {
                    Union(i, EmailToParent[accounts[i][j]]);
                }
                else
                    EmailToParent[accounts[i][j]] = ID[i];
            }
        }

        unordered_map<int, vector<string>> MergedAccount;

        for (auto email : EmailToParent)
        {
            int id = Find(email.second); // always do a Find for getting the right ID
            MergedAccount[id].push_back(email.first);
        }
        vector<vector<string>> result;

        for (auto merged : MergedAccount)
        {
            set<string> St(merged.second.begin(), merged.second.end());
            vector<string> path;
            path.push_back(accounts[merged.first][0]); // name
            for (auto s : St)
                path.push_back(s);
            result.push_back(path);
        }

        return result;
    }
};