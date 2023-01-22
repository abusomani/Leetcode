class Solution
{
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B)
    {
        int N = A.size(), M = B.size();
        if (N > M)
            return findMedianSortedArrays(B, A);
        int low = 0, high = N;
        while (low <= high)
        {
            int i = low + (high - low) / 2;
            int j = (M + N + 1) / 2 - i;

            int A_left = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == N) ? INT_MAX : A[i];
            int B_left = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == M) ? INT_MAX : B[j];

            if (A_left > B_right) // need to select less elements from A
                high = i - 1;
            else if (B_left > A_right) // need to select more elements from A
                low = i + 1;
            else
            {
                // max of lefts and min of rights
                int lmax = max(A_left, B_left), rmin = min(A_right, B_right);
                if ((M + N) & 1)
                    return lmax;
                else
                    return (lmax + rmin) / 2.0;
            }
        }
        return -1;
    }
};