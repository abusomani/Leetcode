class Solution {
private:
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    string transform(string word) {
        string res;
        for(auto &c : word)
            res += morse[c-'a'];
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> unique;
        for(auto &word: words)
            unique.insert(transform(word));
        return unique.size();
    }
};