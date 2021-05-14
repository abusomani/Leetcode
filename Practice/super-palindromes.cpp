using ll = long long;
class Solution
{
public:
    bool check(ll n)
    {
        string r = to_string(n), o = r;
        reverse(r.begin(), r.end());
        return o == r;
    }

    int generatePalindromes(ll left, ll right)
    {
        int res = 0;
        vector<ll> V;
        for (ll i = 1; i <= 9; i++)
            V.push_back(i);
        for (ll i = 1; i <= 1e4; i++)
        {
            string a = to_string(i), b = to_string(i);
            reverse(b.begin(), b.end());
            V.push_back(stoll(a + b));
            for (int i = 0; i <= 9; i++)
                V.push_back(stoll(a + to_string(i) + b));
        }
        for (auto num : V)
        {
            if (num > 1e9)
                continue;
            num *= num;
            if (num >= left and num <= right and check(num))
                res++;
        }
        return res;
    }

    int superpalindromesInRange(string left, string right)
    {
        ll r = stoull(right), l = stoull(left);
        return generatePalindromes(l, r);
    }
};
