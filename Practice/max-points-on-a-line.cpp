/*
[[1,1],[2,2],[3,3]]
[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4],[5,0],[6,-1]]
[[0,0]]
[[1,1],[2,1],[2,2],[1,4],[3,3]]
*/
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<string, int> counter;
            int dup = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
                {
                    dup++;
                }
                else
                {
                    int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1], g = gcd(dx, dy);
                    counter[to_string(dx / g) + '_' + to_string(dy / g)]++;
                }
            }
            ans = max(ans, dup);
            for (auto p : counter)
                ans = max(ans, p.second + dup);
        }
        return ans;
    }

private:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};