/*
Logic is :
    M (34) = 0 1 0 0 0 1
    N (46) = 0 1 1 1 0 1

    If any bit is 0, then definitely in final answer it would be 0
    If both are 1, the difference between the numbers N and M should be less than [(1 << i) - 1] to ensure that all numbers have that bit set
*/
class Solution
{
public:
    int helper(int M, int N)
    {
        // here gap is to maintain the numbers that would have all numbers set at each ith position
        int ans = 0, gap = 0, cnt = 0, m = M, n = N;
        while (M and N)
        {
            int i = M % 2, j = N % 2;
            M >>= 1;
            N >>= 1;
            if (i == 1 and j == 1)
            {
                if (n - m <= gap)
                    ans += (1 << cnt);
            }
            gap = gap * 2 + 1;
            cnt++;
        }

        return ans;
    }
    int rangeBitwiseAnd(int m, int n)
    {
        if (m == 0 or n == 0)
            return 0;
        if (m == n)
            return m;
        return helper(m, n);
    }
};