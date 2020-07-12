/*Input:  "69"
Output: true
Input:  "88"
Output: true
Input:  "1"
Output: true
*/
class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        vector<int> Mp(10, 0);
        Mp[0] = 0;
        Mp[1] = 1;
        Mp[6] = 9;
        Mp[8] = 8;
        Mp[9] = 6;

        string newNum = "";
        for (int i = num.size() - 1; i >= 0; i--)
            newNum.push_back(Mp[num[i] - '0'] + '0');

        return newNum == num;
    }
};