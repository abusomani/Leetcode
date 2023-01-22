class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &A)
    {
        int mx = INT_MIN, idx, N = A.size();
        for (int i = 0; i < N; i++)
        {
            if (A[i] > mx)
            {
                mx = A[i];
                idx = i;
            }
        }
        return idx;
    }
};