// Time complexity => O(N * k^2) ,  k => length of longest word
/*
Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

Edge case - check if empty string exists. 
It's interesting that for given words {"a", ""}, it's expected to return two results [0,1] and [1,0]. 
Since my main logic can cover [0, 1] concatenate("a", ""), so as to cover the other situation concatenate("", "a"), 
I need to traverse the words array again, find the palindrome word candidate except "" itself, 
and add pair("", palindrome word) to the final answer.

Main logic part:
Partition the word into left and right, and see 
1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate. 
2) same for checking the right side of current word: candidate | left | right.
*/
class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        int i, j, N = words.size();
        string left, right, tmp;
        for (i = 0; i < N; i++)
        {
            tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            dict[tmp] = i;
        }

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < words[i].size(); j++)
            {
                left = words[i].substr(0, j); // left part
                right = words[i].substr(j);   // right part
                // left + right + dict[left]
                if (dict.find(left) != dict.end() && dict[left] != i && isPalindrome(right))
                {
                    result.push_back({i, dict[left]});
                    if (left.empty())
                        result.push_back({dict[left], i});
                }
                // dict[right] + left + right
                if (dict.find(right) != dict.end() && dict[right] != i && isPalindrome(left))
                    result.push_back({dict[right], i});
            }
        }
        return result;
    }

private:
    bool isPalindrome(string s)
    {
        int start, end, size = s.size();
        for (start = 0, end = size - 1; start < end; start++, end--)
        {
            if (s[start] != s[end])
                return false;
        }
        return true;
    }
};