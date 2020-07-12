// Important property, A[i][j]'s on same diagonal will always have same value of (i-j) and that would be unique
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int N = mat.size(), M = N ? mat[0].size() : 0;
        if (N == 0 or M == 0)
            return mat;
        unordered_map<int, unordered_map<int, int>> visited;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j])
                {
                    vector<int> grp;
                    int x = i, y = j, idx = 0;
                    while (x < N and y < M)
                        grp.push_back(mat[x++][y++]);

                    sort(grp.begin(), grp.end());

                    x = i;
                    y = j;
                    while (x < N and y < M)
                        mat[x++][y++] = grp[idx++], visited[x][y] = 1;
                }
            }
        }

        return mat;
    }
};