class Solution
{
public:
    vector<int> intersection(vector<int> &A, vector<int> &B)
    {
        const int N = A.size(), M = B.size();
        vector<int> res;
        if (N == 0 or M == 0)
            return res;

        unordered_set<int> St(A.begin(), A.end());
        for (auto &i : B)
        {
            if (St.count(i))
            {
                res.push_back(i);
                St.erase(i);
            }
        }

        return res;
    }
};