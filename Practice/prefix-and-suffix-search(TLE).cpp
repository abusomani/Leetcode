struct Trie {
    unordered_map<char,Trie*> next;
    unordered_set<int> indices;
};
class WordFilter {
private:
    Trie *Orig, *Rev;
    void insert(Trie* curr, string word, int idx){
        for(auto c: word) { 
            if(!curr->next.count(c))
                curr->next[c] = new Trie();
            curr = curr->next[c];
            curr->indices.insert(idx);
        }
    }
    unordered_set<int> search(Trie *curr, string word){
        for(auto c: word){
            if(!curr->next.count(c))
                return {};
            curr = curr->next[c];
        }
        return curr->indices;
    }
    int maxIndex(unordered_set<int> A, unordered_set<int> B){
        int res  = -1;
        for(auto a : A)
            if(B.count(a))
                res = max(res, a);
        return res;
    }
public:
    WordFilter(vector<string>& words) {
        Orig = new Trie();
        Rev = new Trie();
        int idx = 0;
        for(auto word: words){
            insert(Orig, word, idx);
            reverse(word.begin(), word.end());
            insert(Rev, word, idx);
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        return maxIndex(search(Orig, prefix), search(Rev, suffix));
    }
};