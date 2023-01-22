class Solution
{
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

public:
    bool isValid(int x, int y, int N, int M)
    {
        return (x >= 0 and x < N and y >= 0 and y < M);
    }
    vector<int> numIslands2(int n, int m, vector<vector<int>> &positions)
    {
        int mn = m * n, groups = mn;
        vector<int> ID(mn, 0);
        for (int i = 0; i < mn; i++)
            ID[i] = i;

        auto Find = [&](int a) {
            while (ID[a] != a)
            {
                ID[a] = ID[ID[a]];
                a = ID[a];
            }
            return a;
        };

        auto Union = [&](int a, int b) {
            int parentA = Find(a), parentB = Find(b);
            if (parentA == parentB)
                return groups;

            ID[parentB] = ID[parentA];
            return --groups;
        };

        vector<int> islands;
        unordered_set<int> lands;
        for (auto &position : positions)
        {
            int x = position[0], y = position[1];
            int id = x * m + y;
            lands.insert(id);

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (!isValid(newX, newY, n, m))
                    continue;
                int newId = newX * m + newY;
                if (lands.count(newId))
                    Union(id, newId);
            }

            islands.push_back(groups + lands.size() - mn);
        }

        return islands;
    }
};