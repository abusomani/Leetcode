class Solution
{
public:
    vector<char> V = {'0', '1', ' ', ' ', ' ', ' ', '9', ' ', '8', '6'};
    bool isStrobogrammatic(string num)
    {
        int N = num.size(), i = 0, j = N - 1;
        if (N == 0)
            return true;

        while (i <= j) // start and begin match
        {
            if (V[num[i] - '0'] != num[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
};