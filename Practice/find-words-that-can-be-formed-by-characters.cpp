class Solution {
private:
    bool match(vector<int> src, vector<int> &dest){
        for(int i=0; i<26; i++)
            if(src[i] > dest[i])
                return false;
        return true;
    }
    vector<int> convert(string s){
        vector<int> cnt(26, 0);
        for(auto c: s)cnt[c - 'a']++;
        return cnt;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> dest = convert(chars);
        for(auto word: words)
            if(match(convert(word), dest))
                res += word.size();
        return res;
    }
};