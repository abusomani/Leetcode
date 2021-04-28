class Solution {
private:
    bool match(string word, vector<int> &src){
        vector<int> d(26, 0);
        for(auto c: word)
            d[c- 'a']++;
        for(int i=0; i<26; i++)
            if(src[i] > d[i])
                return false;
        return true;
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> src(26, 0);
        for(auto c: licensePlate)
            if(isalpha(c))
                src[tolower(c)-'a']++;
        string res;
        for(auto word: words){
            if(match(word, src))
                res = res.empty() ? word : (res.size() > word.size()) ? word : res;
        }
        return res;
    }
};