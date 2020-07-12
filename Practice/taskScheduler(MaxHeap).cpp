class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int cnt[26] = {0};
        for (auto task : tasks)
            cnt[task - 'A']++;
        priority_queue<int> PQ;

        for (int i = 0; i < 26; i++)
            if (cnt[i])
                PQ.push(cnt[i]);

        int time = 0;
        while (!PQ.empty())
        {
            int i = 0;
            vector<int> tmp;
            while (i <= n) // for a gap of N
            {
                if (!PQ.empty())
                {
                    if (PQ.top() > 1) // if greater than 1, then only we need to add to tmp for next round processing
                        tmp.push_back(PQ.top() - 1);
                    PQ.pop();
                }
                time++;                             // might be idle
                if (PQ.empty() and tmp.size() == 0) // if both heap and tmp are empty
                    break;
                i++;
            }
            for (auto i : tmp) // new count push, even 0 is valid which means idle
                PQ.push(i);
        }

        return time;
    }
};