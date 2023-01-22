/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
//T(n) = 4xT(n/4) + O(1)
// Apply master theorem: n^(log(4)4) = n is O(O(1)). So T(n) = O(n)
/*
____________________
|        |          |
|   2    |     3    |
|________|__________| 
|        |          |
|   1    |    4     |
|________|__________|
*/
class Solution
{
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft)
    {
        if (bottomLeft[0] > topRight[0] or bottomLeft[1] > topRight[1]) // out of bounds rectangle
            return 0;
        if (!sea.hasShips(topRight, bottomLeft)) // if no ship, return
            return 0;
        if (topRight[0] == bottomLeft[0] and topRight[1] == bottomLeft[1]) // implies ship is present, if its a single point, return 1
            return 1;

        int midX = (topRight[0] + bottomLeft[0]) / 2; // mid of X
        int midY = (topRight[1] + bottomLeft[1]) / 2; // mid of Y

        int ways = 0;
        ways += countShips(sea, {midX, midY}, bottomLeft);                       // 1
        ways += countShips(sea, {midX, topRight[1]}, {bottomLeft[0], midY + 1}); // 2, midY + 1 ( starts from next int)
        ways += countShips(sea, topRight, {midX + 1, midY + 1});                 //3, midX+1 and midY+1 for next
        ways += countShips(sea, {topRight[0], midY}, {midX + 1, bottomLeft[1]}); //4, midX+1 (start from next of middle)

        return ways;
    }
};