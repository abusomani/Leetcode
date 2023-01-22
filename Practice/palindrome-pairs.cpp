/*
1. str => reverse(str)
2. left (0, i) right(i+1, str.size)
    a. if reverse of right exists, then reverse(right) + left + right only if left is palindrome
    b. if reverse of left exists, then left + right + reverse(left) only if right is palindrome
    
["abcd","dcba","lls","s","sssll"]
["bat","tab","cat"]
["a",""]
*/
class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        const int N = words.size();
        unordered_map<string, int> lookup;
        for (int i = 0; i < N; i++)
        {
            string word = words[i];
            reverse(word.begin(), word.end());
            lookup[word] = i;
        }
        set<vector<int>> pairs;
        for (int i = 0; i < N; i++)
        {
            string word = words[i];
            for (int j = 0; j < word.size(); j++)
            {
                string left = word.substr(0, j);
                string right = word.substr(j);
                if (lookup.count(right) and isPalindrome(left) and lookup[right] != i)
                    pairs.insert({lookup[right], i});
                if (lookup.count(left) and isPalindrome(right) and lookup[left] != i)
                {
                    pairs.insert({i, lookup[left]});
                    // let say left is empty, then also left + right + reverse(left) would be palindrome. Special case
                    if (left.empty())
                        pairs.insert({lookup[left], i});
                }
            }
        }
        vector<vector<int>> UniquePairs;
        for (auto &pair : pairs)
            UniquePairs.push_back(pair);

        return UniquePairs;
    }

    bool isPalindrome(string s)
    {
        int i = 0, N = s.size(), j = N - 1;
        if (N <= 1)
            return true;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};