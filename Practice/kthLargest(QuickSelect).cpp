class Solution
{
public:
    int findKthLargest(vector<int> &nums, int K)
    {
        int N = nums.size(), l = 0, r = N - 1;
        K = N - K;
        while (l <= r)
        {
            int mid = helper(nums, l, r);
            if (mid == K)
                return nums[mid];
            if (mid < K)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    int helper(vector<int> &A, int l, int r)
    {
        int i = l; // partition [l,r] by A[l]: [l,i]<A[l], [i+1,j)>=A[l]
        for (int j = l + 1; j <= r; j++)
            if (A[j] < A[l])
                swap(A[j], A[++i]);
        swap(A[l], A[i]);
        return i;
    }
};