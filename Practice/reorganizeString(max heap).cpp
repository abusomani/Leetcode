class Solution
{
public:
    string reorganizeString(string S)
    {
        priority_queue<pair<int, char>> PQ;
        int cnt[26] = {0};
        int N = S.size();
        string result = "#";
        for (int i = 0; i < N; i++)
            cnt[S[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt[i]) // non zero count
                PQ.push({cnt[i], i + 'a'});

        while (!PQ.empty())
        {
            pair<int, char> P = PQ.top();
            PQ.pop();
            if (result.back() == P.second)
            {
                if (PQ.empty())
                    return ""; // cant be possible
                else
                {
                    pair<int, char> Q = PQ.top();
                    PQ.pop();
                    PQ.push(P);
                    result += Q.second;
                    Q.first -= 1;
                    if (Q.first > 0)
                        PQ.push(Q);
                    continue;
                }
            }
            else
            {
                result += P.second;
                P.first -= 1;
                if (P.first > 0)
                    PQ.push(P);
            }
        }

        return result.substr(1);
    }
};