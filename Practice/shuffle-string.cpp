class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int N = indices.size();
        string res(N, ' ');
        for (int i = 0; i < N; i++)
            res[indices[i]] = s[i];
        return res;
    }
};