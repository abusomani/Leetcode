class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pCnt(256, 0), sCnt(256, 0);
        int N = s.size(), M = p.size();
        vector<int> result;
        if (M > N)
            return result;

        for (int i = 0; i < M; i++)
            pCnt[p[i]]++, sCnt[s[i]]++;

        for (int i = M; i < N; i++)
        {
            if (pCnt == sCnt)
                result.push_back(i - M);
            sCnt[s[i - M]]--;
            sCnt[s[i]]++;
        }
        if (pCnt == sCnt)
            result.push_back(N - M);

        return result;
    }
};