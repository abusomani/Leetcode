int MAX_TYPES = 2;
class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        deque<int> Dq;
        unordered_map<int, int> Mp;
        int N = tree.size(), begin = 0, end = 0, res = 0;
        while (end < N)
        {
            Dq.push_back(tree[end]);
            Mp[tree[end++]]++;
            while (Mp.size() > MAX_TYPES)
            {
                Mp[tree[begin]]--;
                if (Mp[tree[begin]] == 0)
                    Mp.erase(tree[begin]);
                begin++;
            }
            res = max(res, end - begin);
        }
        return res;
    }
};