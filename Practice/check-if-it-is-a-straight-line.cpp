#define MAX 100005
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int slope(int x1, int y1, int x2, int y2)
    {
        int a = gcd(y2 - y1, x2 - x1);
        if (a == 0)
            return 0;

        return (y2 - y1) / a + MAX * (x2 - x1) / a;
    }
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int N = coordinates.size();
        int diff = slope(coordinates[0][0], coordinates[0][1], coordinates[1][0], coordinates[1][1]);
        for (int i = 1; i < N; i++)
        {
            int newDiff = slope(coordinates[0][0], coordinates[0][1], coordinates[i][0], coordinates[i][1]);
            if (diff != newDiff)
                return false;
        }
        return true;
    }

    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int dY = coordinates[1][1] - coordinates[0][1];
        int dX = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); i++)
        {
            auto p = coordinates[i];
            if (dX * (p[1] - coordinates[0][1]) != dY * (p[0] - coordinates[0][0]))
                return false;
        }
        return true;
    }
};