class Solution {
private:
    int dp[605][101][101];
    void init(){
        for(int i=0; i<605; i++)
            for(int j=0; j<101; j++)
                for(int k=0; k<101; k++)
                    dp[i][j][k] = -1;
    }
    pair<int,int> count(string s){
        int zero = 0;
        for(auto c: s)
            zero += c == '0';
        return {zero, (int)s.size()-zero};
    }
    int fun(vector<pair<int,int>> &V, int m,int n, int zero, int one, int idx){
        // if no strings, largest size of subset is zero
        if(idx == V.size())
            return 0;
        if(dp[idx][zero][one] != -1)
            return dp[idx][zero][one];
        // not including
        int mx = fun(V, m, n,zero,one,idx+1);
        pair<int,int> P = V[idx];
        // include if possible
        if(zero + P.first <= m and one + P.second <= n)
            mx = max(mx, 1 + fun(V, m, n, zero + P.first, one + P.second, idx+1));
        return dp[idx][zero][one] = mx;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        init();
        vector<pair<int,int>> V;
        for(auto &s: strs)
            V.push_back(count(s));
        return fun(V, m, n, 0, 0, 0);
    }
};

class Solution
{
private:
    pair<int, int> count(string s)
    {
        int zero = 0;
        for (auto c : s)
            zero += c == '0';
        return {zero, (int)s.size() - zero};
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        //m zeroes, n ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[i][j] means the largest subset size that can be formed with i zeroes and j ones
        for (auto &s : strs)
        {
            pair<int, int> P = count(s);
            // Catch : have to go from bottom right to top left
            // Why? If a cell in the dp is updated(because s is selected),
            // we should be adding 1 to dp[i][j] from the previous iteration (when we were not considering s)
            // If we go from top left to bottom right, we would be using results from this iteration => overcounting
            for (int i = m; i >= P.first; i--) for (int j = n; j >= P.second; j--)
                dp[i][j] = max(1 + dp[i - P.first][j - P.second], dp[i][j]);
        }
        return dp[m][n];
    }
};