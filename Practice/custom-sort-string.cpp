class Solution
{
public:
    string customSortString(string S, string T)
    {
        vector<int> order(26, INT_MAX);
        for (int i = 0; i < S.size(); i++)
            order[S[i] - 'a'] = i;
        sort(T.begin(), T.end(), [&](const char a, const char b) {
            return order[a - 'a'] == order[b - 'a'] ? a < b : order[a - 'a'] < order[b - 'a'];
        });
        return T;
    }
};