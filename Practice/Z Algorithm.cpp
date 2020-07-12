//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

void computeZ(string str)
{
    ll N = str.size();
    vector<ll> Z(N);
    ll L = 0, R = 0, K;

    for (int i = 1; i < N; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < N and str[R - L] == str[R])
                R++;

            Z[i] = R - L;
            R--;
        }
        else
        {
            K = i - L;

            if (Z[K] < R - i + 1)
                Z[i] = Z[K];

            else
            {
                L = i;
                while (R < N and str[R - L] == str[R])
                    R++;

                Z[i] = R - L;
                R--;
            }
        }
    }
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while (T--)
    {
        ll N, K, x;
        string str;
        cin >> str;

        computeZ(str);
    }
    return 0;
}
// END OF SOURCE CODE