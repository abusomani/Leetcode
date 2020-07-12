class Solution
{
public:
    int myAtoi(string str)
    {
        int num = 0;
        stringstream ss{str};
        ss >> num;
        return num;
    }
};