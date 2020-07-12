/*
https://image.winudf.com/v2/image1/Y29tLnRlc3QuZGlhbGVyX3NjcmVlbl8wXzE1NTAwNTYwNjJfMDk2/screen-0.jpg?fakeurl=1&type=.jpg
dp[i][j] => After ith step, what is the maximum distinct numbers if knight was on jth position
*/
typedef long long ll;
class Solution
{
public:
    const ll MOD = 1e9 + 7;
    const vector<vector<int>> prevPos = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    int knightDialer(int N)
    {
        vector<vector<ll>> dp(N, vector<ll>(10, 0));
        for (int i = 0; i < 10; i++)
            dp[0][i] = 1; // at 0th step all indices are 1 way

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < prevPos[j].size(); k++)
                    dp[i][j] = (dp[i][j] + dp[i - 1][prevPos[j][k]]) % MOD;
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++)
            ans = (ans + dp[N - 1][i]) % MOD;

        return ans;
    }
};