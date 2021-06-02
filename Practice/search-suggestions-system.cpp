int MAX_RESULTS = 3;
struct TrieNode{
    TrieNode *children[26];
    set<string> words;
};
class Solution {
private:
    TrieNode * root;
    vector<vector<string>> res;
    void insert(string word){
        TrieNode *curr = root;
        for(auto c: word){
            if(curr->children[c-'a'] == 0)
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
            curr->words.insert(word);
        }
    }
    void dfs(string searchWord, int idx, TrieNode *curr){
        if(idx == searchWord.size())
            return;
        if(!curr->children[searchWord[idx]-'a'])
        {
            while(idx < searchWord.size())
                res.push_back({}), idx++;
            return;
        }
        else {
            curr = curr->children[searchWord[idx] - 'a'];
            vector<string> V;
            for(auto w: curr->words){
                V.push_back(w);
                if(V.size() == MAX_RESULTS)break;
            }
            res.push_back(V);
            dfs(searchWord, idx+1, curr);
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        for(auto p: products)insert(p);
        dfs(searchWord, 0, root);
        return res;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& P, string SW) {
        sort(P.begin(), P.end());
        int N = P.size() , l = 0, r = N-1, M = SW.size();
        
        vector<vector<string>> result(M);
        for (int i = 0; i < M and l <= r; i++) {
            while (l <= r and (P[l].size() <= i or P[l][i] != SW[i]))
                ++l;
            while (l <= r and (P[r].size() <= i or P[r][i] != SW[i]))
                --r;
            for (int j = l; j <= r and j < l+3; j++) {
                result[i].push_back(P[j]);
            }
        }
        return result;
    }
};