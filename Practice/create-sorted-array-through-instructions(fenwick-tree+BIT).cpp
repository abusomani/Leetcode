#define ll long long
class Solution
{
private:
    const ll MAX = 1e5 + 5, SUB_MAX = MAX - 1, MOD = 1e9 + 7;
    vector<ll> BIT;
    void init()
    {
        BIT.resize(MAX);
        for (ll i = 0; i < MAX; i++)
            BIT[i] = 0;
    }

public:
    void update(ll idx)
    {
        for (ll i = idx; i < MAX; i += i & -i)
            BIT[i]++;
    }
    ll query(ll idx)
    {
        ll sm = 0;
        for (ll i = idx; i > 0; i -= i & -i)
            sm += BIT[i];
        return sm;
    }
    int createSortedArray(vector<int> &instructions)
    {
        init();
        ll ans = 0;
        for (auto &num : instructions)
        {
            update(num);
            ll smaller = query(num - 1) % MOD;
            ll bigger = (query(SUB_MAX) - query(num)) % MOD;
            ans = (ans + min(smaller, bigger)) % MOD;
        }
        return ans;
    }
};