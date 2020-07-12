#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> size, weight;
int S, N;
int dp[2005][2005];
int knapsack(int idx, int sz)
{
    if (idx < 0)
        return 0;
    if (dp[idx][sz] != -1)
        return dp[idx][sz];
    if (size[idx] > sz) // if this is big then dont include
        return dp[idx][sz] = knapsack(idx - 1, sz);
    else // either include or exclude
        return dp[idx][sz] = max(weight[idx] + knapsack(idx - 1, sz - size[idx]), knapsack(idx - 1, sz));
}

int main()
{
    int x, y;
    cin >> S >> N;
    size.clear();
    weight.clear();

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        size.push_back(x);
        weight.push_back(y);
    }

    for (int i = 0; i < 2005; i++)
        for (int j = 0; j < 2005; j++)
            dp[i][j] = -1;

    knapsack(N - 1, S);

    cout << dp[N - 1][S] << endl;

    return 0;
}
