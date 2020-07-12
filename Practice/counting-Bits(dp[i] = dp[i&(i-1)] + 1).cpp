/*
Last set bit is the rightmost set bit. Setting that bit to zero with the bit trick, x &= x - 1, leads to the following transition function:
P(x)=P(x&(x−1))+1;
*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> bits(num + 1, 0);
        for (int i = 1; i <= num; i++)
            bits[i] = bits[(i & (i - 1))] + 1;

        return bits;
    }
};