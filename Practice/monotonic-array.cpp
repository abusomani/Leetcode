class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        const int N = A.size();
        if (N <= 2)
            return true;

        int i = 1;
        while (i < N and A[i - 1] <= A[i])
            i++;

        if (i == N)
            return true;

        i = 1;
        while (i < N and A[i - 1] >= A[i])
            i++;

        return i == N;
    }
};