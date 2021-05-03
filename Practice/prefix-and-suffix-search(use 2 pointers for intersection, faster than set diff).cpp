struct Trie {
    unordered_map<char,Trie*> next;
    vector<int> indices;
};
class WordFilter {
private:
    Trie *Orig, *Rev;
    void insert(Trie* curr, string word, int idx){
        for(auto c: word) { 
            if(!curr->next.count(c))
                curr->next[c] = new Trie();
            curr = curr->next[c];
            curr->indices.push_back(idx);
        }
    }
    vector<int> search(Trie *curr, string word){
        for(auto c: word){
            if(!curr->next.count(c))
                return {};
            curr = curr->next[c];
        }
        return curr->indices;
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
        vector<int> forward = search(Orig, prefix), backward = search(Rev, suffix);
        int i = forward.size()-1, j = backward.size()-1;
        while(i >= 0 and j >= 0){
            if(forward[i] == backward[j])
                return forward[i];
            else if(forward[i] > backward[j])i--;
            else j--;
        }
        return -1;
    }
};