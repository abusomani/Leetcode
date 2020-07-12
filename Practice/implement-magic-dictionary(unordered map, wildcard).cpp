/*
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello","hallo","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
*/
class MagicDictionary
{
public:
    unordered_map<string, char> map;

    void buildDict(vector<string> dict)
    {
        for (string &word : dict)
        {
            for (int i = 0; i < word.size(); i++)
            {
                string mw = word;
                mw[i] = '#';        // wildcard character
                if (!map.count(mw)) // if does not exist
                    map[mw] = word[i];
                else if (map[mw] != word[i]) // hello | hallo , same word but different char
                    map[mw] = '$';           // always valid case
            }
        }
    }

    bool search(string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            string mw = word;
            mw[i] = '#';
            if (map.count(mw) && map[mw] != word[i])
                return true;
        }
        return false;
    }
};