//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Study the pattern : Build lps array of pattern

    Pattern : ababd
    LPS :     00120   number from 1 if there is a match 
    F[i] contains information not only about the largest next partial match for the string under index i but also about every partial match of it. 
    F[i] is the first best partial match, F[F[i]] – is the second best, F[F[F[i]]] – the third, and so on.

    READING : https://cp-algorithms.com/string/prefix-function.html
*/
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

vector<ll> Prefix_Function(string str)
{
    int N = str.size();
    vector<ll> F(N); // failure function or building LPS
    F[0] = 0;        // 0 is default 0

    for (int i = 1; i < N; i++)
    {
        int j = F[i - 1];

        while (j > 0 and str[i] != str[j])
            j = F[j - 1];
        if (str[i] == str[j])
            j++;
        F[i] = j;
    }

    return F;
}

void KMPAlgo(string text, string pattern)
{
    ll N = text.size(), M = pattern.size();

    vector<ll> LPS = Prefix_Function(pattern);
    int i = 0, j = 0; // i for text and j for pattern

    while (i < N)
    {
        while (j > 0 and text[i] != pattern[j])
            j = LPS[j - 1];

        if (text[i] == pattern[j])
            j++;
        i++;
        if (j >= M)
        {
            cout << (i - M) << endl;
            j = LPS[j - 1];
        }
    }
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);

    ll N;
    while (cin >> N, !cin.eof())
    {
        string pattern, text;
        cin >> pattern;
        cin >> text;
        KMPAlgo(text, pattern);
        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE