class Solution
{
private:
    vector<vector<int>> R;
    vector<int> prefix;
    int area(vector<int> &r)
    {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    vector<int> getPoint(vector<int> &r)
    {
        return {
            rand() % (r[2] - r[0] + 1) + r[0],
            rand() % (r[3] - r[1] + 1) + r[1]};
    }

public:
    Solution(vector<vector<int>> &rects)
    {
        R = rects;
        prefix.push_back(0);
        for (auto &i : rects)
            prefix.push_back(area(i) + prefix.back());
    }

    vector<int> pick()
    {
        int weight = rand() % prefix.back();
        int idx = (upper_bound(prefix.begin(), prefix.end(), weight) - prefix.begin()) - 1;
        return getPoint(R[idx]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */