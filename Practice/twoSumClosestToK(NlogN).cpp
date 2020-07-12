class Solution
{
public:
    int twoSumLessThanK(vector<int> &A, int K)
    {
        int N = A.size();
        sort(A.begin(), A.end());
        int res = -1;
        int left = 0, right = N - 1;
        while (left < right)
        {
            int sm = A[left] + A[right];
            if (sm < K)
                res = max(res, sm), left++;
            else
                right--;
        }
        return res;
    }
};