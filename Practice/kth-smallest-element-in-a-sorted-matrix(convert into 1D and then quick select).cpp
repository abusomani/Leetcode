class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> V;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                V.push_back(matrix[i][j]);
        int l = 0, r = V.size() - 1;
        k--;
        while (l <= r)
        {
            int mid = partition(V, l, r);
            if (mid == k)
                return V[mid];
            if (mid < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    int partition(vector<int> &V, int l, int r)
    {
        int i = l;
        for (int j = l + 1; j <= r; j++)
            if (V[j] < V[l])
                swap(V[j], V[++i]);

        swap(V[i], V[l]);
        return i;
    }
};