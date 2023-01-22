/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution
{
public:
    int lower(BinaryMatrix &binaryMatrix, int row, int M)
    {
        int l = 0, r = M; // so to get M as output when element is not present
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (binaryMatrix.get(row, mid) == 1)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> dim = binaryMatrix.dimensions();
        const int N = dim[0], M = dim[1];
        int ans = M;
        for (int i = 0; i < N; i++)
            ans = min(ans, lower(binaryMatrix, i, M));
        return ans == M ? -1 : ans;
    }
};

class Solution1
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> dim = binaryMatrix.dimensions();
        const int N = dim[0], M = dim[1];
        int row = 0, col = M - 1;
        while (row < N and col >= 0)
        {
            if (binaryMatrix.get(row, col) == 0)
                row++;
            else
                col--;
        }

        // If we never left the last column, this is because it was all 0's.
        return (col == M - 1) ? -1 : col + 1;
    }
};