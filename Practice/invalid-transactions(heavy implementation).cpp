class Solution
{
private:
    struct Info
    {
        int id;
        string name;
        long time;
        long amount;
        string city;
    };

public:
    Info getInfo(string s, int id)
    {
        string tmp;
        stringstream ss(s);
        vector<string> V;
        while (getline(ss, tmp, ','))
            V.push_back(tmp);

        assert(V.size() == 4);
        return {id, V[0], stol(V[1]), stol(V[2]), V[3]};
    }
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        const int N = transactions.size();
        vector<bool> invalid(N, false);
        vector<string> res;
        unordered_map<string, vector<Info>> Mp;
        for (int i = 0; i < N; i++)
        {
            Info info = getInfo(transactions[i], i);
            if (info.amount > 1000)
                invalid[info.id] = true;
            if (Mp.count(info.name))
            {
                for (auto other : Mp[info.name])
                {
                    if (other.city != info.city and abs(other.time - info.time) <= 60)
                        invalid[other.id] = true, invalid[info.id] = true;
                }
            }
            Mp[info.name].push_back(info);
        }
        for (int i = 0; i < N; i++)
            if (invalid[i])
                res.push_back(transactions[i]);

        return res;
    }
};