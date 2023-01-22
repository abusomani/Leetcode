class Solution
{
public:
    void merge(vector<int> &a, int m, vector<int> &b, int n)
    {
        int end = m + n - 1;
        m--;
        n--;
        while (n >= 0)
            a[end--] = (m >= 0 and a[m] > b[n]) ? a[m--] : b[n--];
    }
};