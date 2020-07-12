class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> Jewel;
        unordered_map<char, int> stones;
        int M = S.size(), N = J.size();
        for (int i = 0; i < N; i++)
            Jewel.insert(J[i]);
        for (int i = 0; i < M; i++)
            stones[S[i]]++;
        int ans = 0;
        for (auto c : Jewel)
            ans += stones[c];

        return ans;
    }
};

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> Jewel;
        int M = S.size(), N = J.size();
        for (int i = 0; i < N; i++)
            Jewel.insert(J[i]);
        int ans = 0;
        for (auto c : S)
            if (Jewel.find(c) != Jewel.end())
                ans++;

        return ans;
    }
};