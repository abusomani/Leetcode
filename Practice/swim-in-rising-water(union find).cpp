class UF
{
private:
    vector<int> ID;

public:
    UF(int N)
    {
        ID.resize(N);
        for (int i = 0; i < N; i++)
            ID[i] = i;
    }

    int Find(int a)
    {
        while (a != ID[a])
        {
            ID[a] = ID[ID[a]];
            a = ID[a];
        }

        return a;
    }

    bool isConnected(int a, int b)
    {
        return Find(a) == Find(b);
    }

    void Union(int a, int b)
    {
        if (isConnected(a, b))
            return;
        ID[Find(b)] = ID[Find(a)];
    }
};
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int N = grid.size();
        UF uf(N * N);
        int dest = N * N - 1;
        int time = 0;

        while (!uf.isConnected(0, dest))
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] > time)
                        continue;
                    if (i < N - 1 and grid[i + 1][j] <= time)
                        uf.Union(i * N + j, i * N + j + N);
                    if (j < N - 1 and grid[i][j + 1] <= time)
                        uf.Union(i * N + j, i * N + j + 1);
                }
            time++;
        }
        return time - 1;
    }
};