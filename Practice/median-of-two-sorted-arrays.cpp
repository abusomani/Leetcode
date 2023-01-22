/*
<1> Set imin = 0, imax = m, then start searching in [imin, imax]

<2> Set i = (imin + imax)/2, j = (m + n + 1)/2 - i

<3> Now we have len(left_part)==len(right_part). And there are only 3 situations
     that we may encounter:
    <a> B[j-1] <= A[i] and A[i-1] <= B[j]
        Means we have found the object `i`, so stop searching.
    <b> B[j-1] > A[i]
        Means A[i] is too small. We must `ajust` i to get `B[j-1] <= A[i]`.
        Can we `increase` i?
            Yes. Because when i is increased, j will be decreased.
            So B[j-1] is decreased and A[i] is increased, and `B[j-1] <= A[i]` may
            be satisfied.
        Can we `decrease` i?
            `No!` Because when i is decreased, j will be increased.
            So B[j-1] is increased and A[i] is decreased, and B[j-1] <= A[i] will
            be never satisfied.
        So we must `increase` i. That is, we must ajust the searching range to
        [i+1, imax]. So, set imin = i+1, and goto <2>.
    <c> A[i-1] > B[j]
        Means A[i-1] is too big. And we must `decrease` i to get `A[i-1]<=B[j]`.
        That is, we must ajust the searching range to [imin, i-1].
        So, set imax = i-1, and goto <2>.


Finally =>
        max(A[i-1], B[j-1]) (when m + n is odd)
        or (max(A[i-1], B[j-1]) + min(A[i], B[j]))/2 (when m + n is even)
*/
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B)
    {
        const int N = A.size(), M = B.size();
        if (N > M)
            return findMedianSortedArrays(B, A);

        int low = 0, high = N;
        while (low <= high)
        {
            int i = low + (high - low) / 2;
            int j = (N + M + 1) / 2 - i; // for second vector's middle so that sum is half overall

            int A_left = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == N) ? INT_MAX : A[i];
            int B_left = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == M) ? INT_MAX : B[j];

            if (A_left > B_right)
                high = i - 1; // to decrease A_left
            else if (B_left > A_right)
                low = i + 1; // to decrease B_left
            else
            {
                int lMax = max(A_left, B_left), rMin = min(A_right, B_right);
                // if odd, one element is median, i.e. lMax , else (lMax + rMin) / 2
                return (M + N) & 1 ? (double)lMax : (lMax + rMin) / 2.0;
            }
        }
        return -1;
    }
};