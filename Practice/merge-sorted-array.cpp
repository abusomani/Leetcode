class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {
        int last = m + n - 1, i = m - 1, j = n - 1;
        while (last >= 0 and i >= 0 and j >= 0)
        {
            A[last--] = A[i] > B[j] ? A[i--] : B[j--];
        }
        while (last >= 0 and i >= 0)
            A[last--] = A[i--];
        while (last >= 0 and j >= 0)
            A[last--] = B[j--];
    }
};