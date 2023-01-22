class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string start;
        for (int i = 1; i <= n; i++)
            start += to_string(i);

        while (--k)
            next_permutation(start);
        return start;
    }
    void next_permutation(string &s)
    {
        int k, l, N = s.size();
        for (k = N - 2; k >= 0; k--)
            if (s[k] < s[k + 1])
                break;
        if (k < 0)
            return;
        for (l = N - 1; l > k; l--)
            if (s[l] > s[k])
                break;

        swap(s[l], s[k]);
        reverse(s.begin() + k + 1, s.end());
    }
};