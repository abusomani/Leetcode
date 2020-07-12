/*
Sort the words alphabetically, therefore shorter words always comes before longer words;
Along the sorted list, populate the words that can be built;
Any prefix of a word must comes before that word.
*/
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words)
        {
            if (w.size() == 1 or built.count(w.substr(0, w.size() - 1)))
            {
                res = w.size() > res.size() ? w : res;
                built.insert(w); // insert only if previous is present then only chain will continue
            }
        }
        return res;
    }
};