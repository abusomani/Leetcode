class Solution
{
public:
    vector<string> generatePalindromes(string s)
    {
        unordered_map<char, int> count;
        vector<string> palindromes;
        int odd = 0;
        char oddChar;
        string half;
        for (auto c : s)
            count[c]++;
        for (auto i : count)
        {
            if (i.second & 1)
            {
                odd++;
                oddChar = i.first;
            }
            if (odd > 1)
                return palindromes;
            half += string(i.second >> 1, i.first);
        }

        unordered_set<string> palinHalves = generatePalinUtil(half);

        for (auto str : palinHalves)
        {
            string strRev = str;
            reverse(strRev.begin(), strRev.end());
            if (odd)
            {
                str += string(1, oddChar);
            }
            str += strRev;
            palindromes.push_back(str);
        }
        return palindromes;
    }

    unordered_set<string> generatePalinUtil(string half)
    {
        unordered_set<string> palin;
        sort(half.begin(), half.end());
        while (true)
        {
            palin.insert(half);
            if (!next_permutation(half.begin(), half.end()))
                break;
        }

        return palin;
    }
};