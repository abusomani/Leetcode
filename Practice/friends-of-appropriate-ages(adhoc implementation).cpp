class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        vector<int> Ages(125, 0);
        for (auto age : ages)
            Ages[age]++;

        int ans = 0;
        for (int a = 0; a < 125; a++)
        {
            int cntA = Ages[a];
            for (int b = 0; b < 125; b++)
            {
                int cntB = Ages[b];
                if (a * 0.5 + 7 >= b)
                    continue;
                if (b > a)
                    continue;
                if (a < 100 and b > 100)
                    continue;
                ans += cntA * cntB;
                if (a == b)
                    ans -= cntA;
            }
        }

        return ans;
    }
};