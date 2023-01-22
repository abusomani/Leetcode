class Solution
{
public:
    string removeDuplicates(string S)
    {
        vector<char> V;
        V.push_back('#');
        for (auto &c : S)
        {
            if (V.back() == c)
            {
                while (V.back() == c)
                    V.pop_back();
            }
            else
                V.push_back(c);
        }
        string ans;
        for (auto &i : V)
            ans += i;

        return ans.substr(1);
    }
};