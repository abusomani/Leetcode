class Solution
{
public:
    // diagonal [x1,y1] and [x2, y2] then find if [x1, y2] and [x2, y1] exists
    int minAreaRect(vector<vector<int>> &points)
    {
        /**
        * Base case: we need at least 4 points to form a rectangle
        */
        if (points.size() < 4)
            return 0;

        /**
        * minArea: result 
        * pointSet: stores all the points
        *   (we can use unordered_set here to reduce the time complexity, 
        *    but be aware that in C++ unordered_set doesn't not take type of vector or pair
        *    unless you create a hasher)
        *   referenes:
        *       unordered_set<vector<int>>: https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
        *       unordered_set<pair<int, int>>: https://stackoverflow.com/questions/15160889/how-to-make-unordered-set-of-pairs-of-integers-in-c
        */
        int minArea = INT_MAX;
        unordered_set<int> pointSet;

        for (auto point : points)
            pointSet.insert(point[1] * 40001 + point[0]);

        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                /**
                * Check if current points pair (<x1, y1> & <x2, y2>) can form a diagonal 
                *   If (true): 
                *       check if point <x1, y2> && point <x2, y1> exists
                *           If yes:
                *               1. calculate the curArea
                *               2. update the minArea if curArea > minArea
                *           Else:
                *               continue checking next possible pair;
                *   Else: 
                *       continue checking next possible pair;
                */
                int xOne = points[i][0], yOne = points[i][1];
                int xTwo = points[j][0], yTwo = points[j][1];

                if (xOne != xTwo && yOne != yTwo && xOne != yTwo && yOne != xTwo)
                {
                    if (pointSet.count(yTwo * 40001 + xOne) && pointSet.count(yOne * 40001 + xTwo))
                    {
                        int curArea = (abs(xTwo - xOne) * abs(yTwo - yOne));
                        minArea = min(minArea, curArea);
                    }
                }
            }
        }

        return minArea == INT_MAX ? 0 : minArea;
    }
};