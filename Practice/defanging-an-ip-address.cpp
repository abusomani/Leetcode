class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res = "";
        for (auto &c : address)
            res += (c == '.') ? "[.]" : string(1, c);
        return res;
    }
};