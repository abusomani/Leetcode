class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int N = bits.size();
        if (N == 1)
            return true;

        int l = 0, jump = 0; // last jump tells what it was
        while (l < N)
        {
            if (bits[l] == 1)
                l += 2, jump = 2;
            else if (bits[l] == 0)
                l++, jump = 1;
        }
        return (jump == 1) ? true : false;
    }
};