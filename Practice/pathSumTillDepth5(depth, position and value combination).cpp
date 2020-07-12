/*
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
*/
class Solution
{
private:
    int tree[5][8] = {};

public:
    int pathSum(vector<int> &nums)
    {
        int depth, position, value;
        for (auto num : nums)
        {
            depth = num / 100;
            position = ((num / 10) % 10) - 1;
            value = num % 10;
            tree[depth][position] = tree[depth - 1][position / 2] + value; // store tree by 1-indexed, but prefix sum
        }
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                //either last row
                // or leaf in intermediate rows
                if (i == 4 or (tree[i][j] and !tree[i + 1][j * 2] and !tree[i + 1][j * 2 + 1]))
                {
                    ans += tree[i][j];
                }
            }
        }

        return ans;
    }
};