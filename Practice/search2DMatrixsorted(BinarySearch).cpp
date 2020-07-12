class Solution
{
public:
    bool binarySearch(vector<int> A, int target)
    {
        int N = A.size();
        if (N == 0)
            return false;
        int low = 0, high = N - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (A[mid] == target)
                return true;
            else if (A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int K)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        if (N == 0 or M == 0) // no rows or no columns
            return false;
        int rowToBeSearched = -1;
        while (rowToBeSearched + 1 < N and matrix[rowToBeSearched + 1][0] <= K)
            rowToBeSearched++;
        /*
        [[1]]
        0
        In this case rowToBeSearched will remain -1
        */
        return rowToBeSearched != -1 ? binarySearch(matrix[rowToBeSearched], K) : false;
    }
};