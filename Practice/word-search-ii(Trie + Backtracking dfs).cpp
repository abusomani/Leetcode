class Trie
{
public:
    Trie *next[26];
    bool isWord;

    Trie()
    {
        fill_n(next, 26, nullptr);
        isWord = false;
    }

    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
            delete next[i];
    }

    void insert(const string &t)
    {
        Trie *iter = this;
        for (int i = 0; i < t.size(); ++i)
        {
            if (iter->next[t[i] - 'a'] == nullptr)
                iter->next[t[i] - 'a'] = new Trie();
            iter = iter->next[t[i] - 'a'];
        }
        iter->isWord = true;
    }
};

class Solution
{
public:
    int m, n;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *trie = new Trie();
        for (auto &s : words)
            trie->insert(s);
        m = board.size();
        n = board[0].size();

        vector<string> ret;
        string sofar;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(board, ret, sofar, trie, i, j);
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>> &board, vector<string> &ret, string &sofar, Trie *root, int x, int y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0' || root == nullptr)
            return;
        if (root->next[board[x][y] - 'a'] == nullptr)
            return;
        root = root->next[board[x][y] - 'a'];
        char t = '\0';
        swap(t, board[x][y]);
        sofar.push_back(t);
        if (root->isWord)
        {
            root->isWord = false; // to avoid duplicate addition
            ret.push_back(sofar);
        }
        dfs(board, ret, sofar, root, x, y + 1);
        dfs(board, ret, sofar, root, x + 1, y);
        dfs(board, ret, sofar, root, x - 1, y);
        dfs(board, ret, sofar, root, x, y - 1);
        swap(t, board[x][y]); // backtracking
        sofar.pop_back();
    }
};