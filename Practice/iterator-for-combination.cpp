const int MAX = 1e5;
class CombinationIterator
{
private:
    set<string> St;
    set<string>::iterator it;
    void generate(string S, int K)
    {
        int N = S.size(), total = (1 << N);
        for (int i = 0; i < total; i++)
        {
            int cnt = 0;
            string res = "";
            for (int j = 0; j < N; j++)
                if (i & (1 << j))
                    res += S[j], cnt++;

            if (cnt == K)
                St.insert(res);
        }
    }

public:
    CombinationIterator(string S, int K)
    {
        generate(S, K);
        it = St.begin();
    }

    string next()
    {
        if (hasNext())
        {
            string res = *it;
            it++;
            return res;
        }
        else
            return "";
    }

    bool hasNext()
    {
        return (it != St.end());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */