class Solution
{
public:
    int lower(vector<int> &A, int X)
    {
        int N = A.size(), l = 0, r = N;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (A[mid] >= X)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> findClosestElements(vector<int> &A, int K, int X)
    {
        int N = A.size();
        int low = lower(A, X);
        int left = max(0, low - K), right = min(N - 1, low + K - 1);
        // reduce the boundary
        while (right - left + 1 > K)
        {
            if (abs(X - A[left]) <= abs(X - A[right]))
                right--;
            else
                left++;
        }
        return vector<int>(A.begin() + left, A.begin() + left + K);
    }
};