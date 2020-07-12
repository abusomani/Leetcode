/*
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string result = "", tmp;
        stringstream ss(address);
        while (getline(ss, tmp, '.'))
        {
            result += tmp + "[.]";
        }

        return result.substr(0, result.size() - 3);
    }
};