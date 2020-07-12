/*
    M-1 possibilities and N-1 possibilities to reach end.
    Total ways : (M-1 + N-1) C (M-1)
    i.e. = (M+N-2)! / (M-1)!(N-1)!
*/
typedef long long ll;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        m--;
        n--;
        ll result = 1, len = m + n;
        int big = max(m, n);
        for (int i = big + 1, j = 1; i <= len; i++, j++)
        {
            result *= i;
            result /= j;
        }

        return result;
    }
};