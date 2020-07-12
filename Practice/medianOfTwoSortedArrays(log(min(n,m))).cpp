class Solution
{
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B)
    {
        int m = A.size();
        int n = B.size();
        if (m > n)
            return findMedianSortedArrays(B, A);

        int low = 0, high = m;
        while (low <= high)
        {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;

            int A_left = i == 0 ? INT_MIN : A[i - 1];
            int A_right = i == m ? INT_MAX : A[i];
            int B_left = j == 0 ? INT_MIN : B[j - 1];
            int B_right = j == n ? INT_MAX : B[j];

            if (A_left > B_right)
                high = i - 1;
            else if (B_left > A_right)
                low = i + 1;
            else
            {
                int lmax = max(A_left, B_left), rmin = min(A_right, B_right);
                if ((m + n) & 1)
                    return lmax;
                else
                    return (lmax + rmin) / 2.0;
            }
        }

        return -1;
    }
};