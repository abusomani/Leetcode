/*
In the post there is a section, it happens to fit this problem.

https://leetcode.com/uploads/files/1480687979438-upload-a602a806-be8c-410c-b086-8985cf705c3d.png

This snippet of code is aim to find the first x for which p(x) is true

https://leetcode.com/uploads/files/1480688086249-upload-3e0c9a59-1ef7-491f-ba08-8d107c166b5e.png

Suppose matrix = [ [1,7], [8, 10] ] and k=2.

Using Binary Search, we should

Define the Search space: [1..10]
Design the predict: p(x) is count( (numbers in matrix) <= x ) >= k
So in the problem, we are going to find the first element x for which p(x) is true, for which count of numbers in [ [1,7], [8, 10] ] 
less or equal than x just >=2.

https://leetcode.com/uploads/files/1480688589340-upload-c94ca21d-0281-43bb-9971-96ecd3b27b3f.png

The element (lo) must be in the matrix to be the first one to make the prediction truth.
*/
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int count = countNum1(matrix, mid);
            if (count < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int countNum(vector<vector<int>> &matrix, int mid)
    {
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++)
            ans += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

        return ans;
    }
    int countNum1(vector<vector<int>> &matrix, int mid) // more efficient
    {
        int ans = 0;
        int n = matrix.size(), i = n - 1, j = 0;
        while (i >= 0 and j < n)
        {
            if (matrix[i][j] > mid)
                i--;
            else
            {
                ans += (i + 1);
                j++;
            }
        }
        return ans;
    }
};