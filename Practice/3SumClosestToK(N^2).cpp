class Solution
{
public:
    int threeSumClosest(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        int N = A.size();
        int res = -1, diff = INT_MAX;
        for (int i = 0; i < N - 2; i++)
        {
            if (i and A[i] == A[i - 1])
                continue; // already processed

            int j = i + 1, k = N - 1;
            while (j < k)
            {
                int sm = A[i] + A[j] + A[k];
                if (sm == K)
                    return K;
                if (abs(sm - K) < diff)
                {
                    diff = abs(sm - K);
                    res = sm;
                }
                if (sm < K)
                    j++;
                else if (sm > K)
                    k--;
            }
        }
        return res;
    }
};