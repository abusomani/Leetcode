/*
Lsum, sum of the last L elements
Msum, sum of the last M elements

Lmax, max sum of contiguous L elements before the last M elements.
Mmax, max sum of contiguous M elements before the last L elements/
*/
class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
    {
        int N = A.size();
        vector<int> preSum = {0};
        for (auto num : A)
            preSum.push_back(preSum.back() + num);
        // imagine the first array starts at position 0
        int max_val = preSum[L + M], l_max = preSum[L], m_max = preSum[M];
        for (int i = L + M + 1; i <= N; i++)
        {
            //case 1: L subarray is always before M subarray
            l_max = max(l_max, preSum[i - M] - preSum[i - L - M]);
            //case 2: M subarray is always before L subarray
            m_max = max(m_max, preSum[i - L] - preSum[i - L - M]);
            max_val = max(max_val,
                          max(l_max + preSum[i] - preSum[i - M],
                              m_max + preSum[i] - preSum[i - L]));
        }

        return max_val;
    }
};