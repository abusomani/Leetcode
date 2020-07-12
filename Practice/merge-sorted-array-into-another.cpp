#include <bits/stdc++.h>
using namespace std;

/*
    merge one array into another, sufficient size, both arrays are sorted.

    Logic is to start from back, place the larger element using end index. If you start from front, you will face shifting challenges
*/
class Solution
{
public:
    void merge(vector<int> &a, int m, vector<int> &b, int n)
    {
        int end = m + n - 1;
        m--;
        n--;
        while (n >= 0)
            a[end--] = (m >= 0 && a[m] > b[n]) ? a[m--] : b[n--];
    }
};