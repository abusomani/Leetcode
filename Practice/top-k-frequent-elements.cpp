class Solution
{
public:
    struct compare
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first > b.first;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> Mp;
        for (auto &num : nums)
            Mp[num]++;

        // priority_queue<pair<int,int> , vector<pair<int,int>>, compare> MnHp;
        priority_queue<pair<int, int>> MnHp; // Max Heap with negative count is same as min heap

        for (auto &i : Mp)
        {
            MnHp.push({-i.second, i.first});
            if (MnHp.size() > k)
                MnHp.pop();
        }
        vector<int> res;
        while (!MnHp.empty())
        {
            res.push_back(MnHp.top().second);
            MnHp.pop();
        }
        return res;
    }
};