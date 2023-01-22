class Solution
{
private:
    vector<vector<int>> dir = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};

public:
    string coordToString(int x, int y)
    {
        return to_string(x) + "#" + to_string(y);
    }
    int minKnightMoves(int x, int y)
    {
        if (x == 0 and y == 0)
            return 0;
        if (x == 1 and y == 1)
            return 2;

        int ans = 0;
        queue<pair<int, int>> Q;
        unordered_set<string> St;
        Q.push({0, 0});
        St.insert("0#0");
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                pair<int, int> P = Q.front();
                Q.pop();
                if (P.first == x and P.second == y)
                    return ans;

                int j = whereToGo(x, y, P.first, P.second);
                for (int i = j; i <= j + 1; i++)
                {
                    int newX = P.first + dir[i][0], newY = P.second + dir[i][1];
                    if (newX == x and newY == y)
                        return ans + 1;
                    string newCoord = coordToString(newX, newY);
                    // early termination as the node wont go deep for encountering this visited node
                    if (!St.count(newCoord))
                        St.insert(newCoord), Q.push({newX, newY});
                }
            }
            ans++;
        }
        return -1;
    }
    int whereToGo(int x, int y, int a, int b)
    {
        if (x >= a and y >= b)
            return 0;
        else if (x <= a and y >= b)
            return 2;
        else if (x <= a and y <= b)
            return 4;
        else
            return 6;
    }
};