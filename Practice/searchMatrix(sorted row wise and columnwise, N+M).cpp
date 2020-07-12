class Solution
{
public:
    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    bool searchMatrix(vector<vector<int>> &matrix, int K)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0, left = 0, right = M - 1;
        if (N == 0)
            return false;
        while (true)
        {
            if (!isValid(left, right, N, M))
                break;
            if (matrix[left][right] == K)
                return true;
            if (matrix[left][right] > K)
                right--;
            else if (matrix[left][right] < K)
                left++;
        }

        return false;
    }
};