class Solution
{
private:
    vector<int> power;
    string ret;
    int MOD = 19260817;
    string RabinKarp(string &s, int &k)
    {
        if (k == 0)
            return "";

        long long int hash = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = k - 1; i >= 0; i--)
            hash = (hash % MOD + (power[k - 1 - i] * (s[i] - 'a' + 1)) % MOD) % MOD;

        int i = 0, j = k - 1;
        mp[hash] = vector<int>(1, 0);
        bool flag = 0;
        while (j < s.size())
        {
            hash = (hash % MOD - ((power[k - 1] * (s[i] - 'a' + 1)) % MOD) + MOD) % MOD;
            hash = (hash % MOD * 26 % MOD) % MOD;
            i++;
            j++;
            if (j < s.size())
            {
                hash = (hash % MOD + ((power[0] * (s[j] - 'a' + 1)) % MOD)) % MOD;
                if (mp.find(hash) != mp.end())
                {
                    for (auto ind : mp[hash])
                    {
                        if (strcmp((s.substr(ind, k)).data(), s.substr(i, k).data()) == 0)
                        {
                            return s.substr(ind, k);
                        }
                    }
                    mp[hash].push_back(i);
                }
                else
                {
                    mp[hash] = vector<int>(1, i);
                }
            }
        }
        return "";
    }

    void init(int N)
    {
        power.resize(N + 1);
        power[0] = 1;
        for (int i = 1; i < N; i++)
            power[i] = (26 * power[i - 1]) % MOD;
    }

public:
    string longestDupSubstring(string S)
    {
        int N = S.size();
        if (N == 0)
            return "";

        init(N);

        string ans;
        int l = 0, r = N;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            string val = RabinKarp(S, mid);
            if (val.size() > 0)
            {
                ans = val;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};