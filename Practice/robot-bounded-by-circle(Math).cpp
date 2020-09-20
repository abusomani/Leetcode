//The robot stays in the circle iff (looking at the final vector) it changes direction (ie. doesn't stay pointing north), or it moves 0.
class Solution
{
private:
    int dx[4] = {0, -1, 0, 1}; // N W S E
    int dy[4] = {1, 0, -1, 0};

public:
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0;
        int up = 0;
        vector<pair<pair<int, int>, int>> V;
        for (auto &c : instructions)
        {
            if (c == 'G')
                x += dx[up], y += dy[up];
            else if (c == 'L')
                up = (up + 1) % 4;
            else
                up = (up + 3) % 4;
            V.push_back({{x, y}, up});
        }
        if (V.back().second == 0 and (V.back().first.first != 0 or V.back().first.second != 0)) // if facing north and not at origin, definitely false
            return false;
        return true;
    }
};