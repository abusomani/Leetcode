class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    bool hasGroupsSizeX(vector<int> &deck)
    {
        int N = deck.size();
        if (N <= 1)
            return false;
        if (N == 2)
            return deck[0] == deck[1];

        unordered_map<int, int> Mp;
        for (auto &card : deck)
            Mp[card]++;

        int X = 0;
        for (auto &p : Mp)
            X = gcd(X, p.second);
        return X >= 2;
    }
};