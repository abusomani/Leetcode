class Solution {
private:
    unordered_set<string> generateWords(string word, unordered_set<string> &Unique) {
        unordered_set<string> St;
        int N = word.size();
        for(int i=0; i<N; i++) {
            char original = word[i];
            for(char c='a';c<='z'; c++) {
                word[i] = c;
                if(c != original and Unique.count(word))
                    St.insert(word);
            }
            word[i] = original;
        }
        return St;
    }
public:
    int BFS(string beginWord, string endWord, unordered_set<string> &Unique){
        int level = 1;
        unordered_set<string> visited;
        queue<string> Q;
        Q.push(beginWord);
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                string word = Q.front(); Q.pop();
                visited.insert(word);
                for(auto &new_word : generateWords(word, Unique)) {
                    if(new_word == endWord)
                        return level+1;
                    if(!visited.count(new_word)) {
                        visited.insert(new_word);
                        Q.push(new_word);
                    }
                }
            }
            level++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& W) {
        unordered_set<string> Unique(W.begin(), W.end());
        return BFS(beginWord, endWord, Unique);
    }
};