class Solution
{
public:
    vector<int> intersect(vector<int> &A, vector<int> &B)
    {
        if (A.size() == 0 or B.size() == 0)
            return {};
        unordered_map<int, int> Mp;
        for (auto &i : A)
            Mp[i]++;
        vector<int> res;
        for (auto &i : B)
            if (Mp[i]-- > 0)
                res.push_back(i);

        return res;
    }
};