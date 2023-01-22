class Solution
{
private:
    int N, M;

public:
    int numberOfLarger(vector<vector<int>> &matrix, int num)
    {
        int count = 0;
        for (int i = 0; i < N; i++)
            count += upper_bound(matrix[i].begin(), matrix[i].end(), num) - matrix[i].begin();
        return count;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        N = matrix.size(), M = matrix[0].size();
        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                mx = max(mx, matrix[i][j]), mn = min(mn, matrix[i][j]);

        int l = mn, r = mx;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (numberOfLarger(matrix, mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};