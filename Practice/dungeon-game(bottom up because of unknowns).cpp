/*
[[0,0,0],[1,1,-1]]
[[0,0,0]]
[[-2,-3,3],[-5,-10,1],[10,30,-5]]
[[100]]
[[-3,5]]
Because it is known that the knight has to reach the end with at least one health point 
and the health point with which the knight should start with is not known.


Dynamic Programming
First, we need to define the subproblem somewhat a little clever. If we define:
dp[i][j] = minimum cost from (0, 0) to (i, j)
It won't help solving the problem, because the result of dp[i + 1][j + 1] does not depends only on previous solve subproblems, but also future unsolved subproblems. 
So, how about let's define the subproblem from the other end of the puzzle?
dp[i][j] = minimum health level required to reach the princess when entering (i, j)

So, what is dp[i + 1][j + 1] then? It depends on the minimum between dp[i][j + 1] and dp[i + 1][j], 
because we want to choose the cheapest way to go. Of course we also need to add or deduct the value from dungeon matrix. 
But be careful, if we find that the minimum required health level is less that 0, we need to set it to 0, because we are not allowed to overdraft health. With that said:
dp[i + 1][j + 1] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i + 1][j + 1], 0);
*/
class Solution
{
public:
    int val(int a)
    {
        return a <= 0 ? 1 : a;
    }
    int calculateMinimumHP(vector<vector<int>> &D)
    {
        int N = D.size(), M = N ? D[0].size() : 0;
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
        dp[N][M - 1] = 1;
        dp[N - 1][M] = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = M - 1; j >= 0; j--)
            {
                int hp = min(dp[i + 1][j], dp[i][j + 1]) - D[i][j];
                dp[i][j] = val(hp);
            }
        }

        return dp[0][0];
    }
};

class Solution
{
    int[][] mem;

    int helper(int[][] dungeon, int i, int j)
    {
        if (i >= dungeon.length || j >= dungeon[0].length)
            return Integer.MAX_VALUE;
        if (mem[i][j] > 0)
            return mem[i][j];
        int health = Integer.MAX_VALUE;
        health = Math.min(health, helper(dungeon, i + 1, j));
        health = Math.min(health, helper(dungeon, i, j + 1));
        health = health == Integer.MAX_VALUE ? 1 : health; // this only happens with i, j is P already
        int ret = health > dungeon[i][j] ? (health - dungeon[i][j]) : 1;
        mem[i][j] = ret;
        return ret;
    }
    int calculateMinimumHP(int[][] dungeon)
    {
        if (dungeon.length == 0)
            return 0;
        mem = new int[dungeon.length][dungeon[0].length];
        return helper(dungeon, 0, 0);
    }
}