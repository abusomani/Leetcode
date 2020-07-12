//https://leetcode.com/problems/minimum-knight-moves/discuss/479803/Quadrant-based-BFS-solution-explained
//https://assets.leetcode.com/users/justkeepcodinggg/image_1578966446.png
static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
    vector<pair<int, int>> directions = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
    unordered_set<string> visited;
    int m, n;

public:
    int minKnightMoves(int x, int y)
    {
        if (x == 0 && y == 0)
            return 0;
        /* Workaround in case of x=1 and y=1 */
        if (x == 1 && y == 1)
            return 2;

        int ans = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited.insert("0#0");

        while (true)
        {
            int N = q.size();
            while (N--)
            {

                pair<int, int> P = q.front();
                q.pop();

                int i = findNextQuadrant(x, y, P.first, P.second);

                for (int n = i; n <= i + 1; ++n)
                { /* Every quadrant as 2 points */
                    int newX = P.first + directions[n].first;
                    int newY = P.second + directions[n].second;
                    if (newX == x && newY == y)
                        return ans + 1;

                    string hash = to_string(newX) + "#" + to_string(newY);
                    if (visited.find(hash) == visited.end())
                    {
                        visited.insert(hash);
                        q.push(make_pair(newX, newY));
                    }
                }
            }
            ans++;
        }
    }

    int findNextQuadrant(int x1, int y1, int x2, int y2)
    {
        if (x1 - x2 >= 0 && y1 - y2 >= 0) /* Target is in 1st quadrant */
            return 0;
        else if (x1 - x2 < 0 && y1 - y2 >= 0) /* Target is in 2nd quadrant */
            return 2;
        else if (x1 - x2 < 0 && y1 - y2 < 0) /* Target is in 3rd quadrant */
            return 4;
        return 6; /* Target is in 4th quadrant */
    }
};