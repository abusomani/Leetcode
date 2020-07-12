class Solution
{
public:
    const string ABC = "abc";
    bool isValid(string S)
    {
        vector<char> V;
        for (auto &c : S)
        {
            if (c == 'c')
            {
                int N = V.size();
                if (N < 2 or V[N - 1] != 'b' or V[N - 2] != 'a')
                    return false;

                V.pop_back();
                V.pop_back();
            }
            else
                V.push_back(c);
        }
        return V.size() == 0;
    }
    bool isValidErase(string S)
    {
        while (true)
        {
            if (S.find(ABC) == string::npos)
                return S.size() == 0;
            S.erase(S.find(ABC), 3);
        }
        return false;
    }
};