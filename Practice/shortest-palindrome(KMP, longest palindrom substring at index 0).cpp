class Solution
{
public:
    //Alternative problem "find the longest palindrome substring starts from index 0".
    string shortestPalindrome(string s)
    {
        int N = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());

        string newS = s + "#" + rev; // KMP on this string, last index will have length of longest palindrome at index 0
        int newN = newS.size();
        vector<int> lps(newN, 0);

        for (int i = 1; i < newN; i++)
        {
            int t = lps[i - 1];
            while (t and newS[t] != newS[i])
                t = lps[t - 1];

            if (newS[t] == newS[i])
                t++;
            lps[i] = t;
        }
        string non_palin = s.substr(lps[newN - 1]);
        reverse(non_palin.begin(), non_palin.end());
        return non_palin + s;
    }
};