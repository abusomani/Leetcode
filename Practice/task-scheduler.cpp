class Solution
{
public:
    /*
        A B C D
        A B C D
        A B C -
        A B - -
        A B
        
        
        A B -
        A B -
        A B
    */
    int leastInterval(vector<char> &tasks, int n)
    {
        priority_queue<int> PQ;
        vector<int> cnt(26, 0);
        for (auto &c : tasks)
            cnt[c - 'A']++;

        for (int i = 0; i < 26; i++)
            if (cnt[i])
                PQ.push(cnt[i]);

        int ans = 0;
        while (!PQ.empty())
        {
            vector<int> tmp;
            int i = 0;
            while (i <= n)
            {
                if (!PQ.empty())
                {
                    int val = PQ.top();
                    PQ.pop();
                    if (val > 1)
                        tmp.push_back(val - 1);
                }
                ans++;
                if (tmp.empty() and PQ.empty())
                    break;
                i++;
            }
            for (auto &i : tmp)
                PQ.push(i);
        }

        return ans;
    }
};