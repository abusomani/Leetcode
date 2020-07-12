class Solution
{
public:
    int check(vector<int> &A, vector<int> &B, int N, int val)
    {
        int cntA = 0, cntB = 0;
        for (int i = 0; i < N; i++)
        { 
            if (A[i] != val and B[i] != val)
                return -1;
            // making equal in A
            if (A[i] != val and B[i] == val)
                cntA++;
            // making equal in B
            if (A[i] == val and B[i] != val)
                cntB++;
        }
        return min(cntA, cntB);
    }

    int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        int N = A.size();
        int cnt[7] = {0};
        for (int i = 0; i < N; i++)
            cnt[A[i]]++, cnt[B[i]]++;
        int ans = INT_MAX;
        for (int i = 1; i <= 6; i++)
        {
            if (cnt[i] >= N)
            {
                ans = min(ans, check(A, B, N, i));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};