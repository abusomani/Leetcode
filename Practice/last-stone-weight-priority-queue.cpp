//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//[31,26,33,21,40] => Greedy fails ( Answer should be 5, greedy gives 9)
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        if (stones.size() == 1)
            return stones[0];

        priority_queue<int> PQ;
        for (int i = 0; i < stones.size(); i++)
            PQ.push(stones[i]);

        while (PQ.size() > 1)
        {
            ll a = PQ.top();
            PQ.pop();
            ll b = PQ.top();
            PQ.pop();

            ll val = max(a, b) - min(a, b);
            if (val)
                PQ.push(val);
        }
        if (PQ.size() == 0)
            return 0;
        else
            return PQ.top();
    }
};