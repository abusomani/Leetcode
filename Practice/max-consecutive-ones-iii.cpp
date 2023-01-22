class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int N = A.size(), begin = 0, end = 0, zero = 0, ans = INT_MIN;

        while (end < N)
        {
            if (A[end++] == 0)
                zero++;
            while (zero > K)
            {
                if (A[begin++] == 0)
                    zero--;
            }
            ans = max(ans, end - begin);
        }

        return ans;
    }
};