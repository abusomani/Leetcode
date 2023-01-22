class Solution
{
private:
    struct Trie
    {
        unordered_map<char, Trie *> children;
        bool isEndOfWord = false;
        string word;
    };
    Trie *root;
    void add(string s)
    {
        Trie *curr = root;
        for (auto &c : s)
        {
            if (!curr->children.count(c))
                curr->children[c] = new Trie();
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
        curr->word = s;
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int x, int y, int N, int M)
    {
        return (x >= 0 and x < N and y >= 0 and y < M);
    }

public:
    string coordToString(pair<int, int> P)
    {
        return to_string(P.first) + "#" + to_string(P.second);
    }

    void dfs(vector<vector<char>> &board, Trie *curr, int x, int y, int &N, int &M, unordered_set<string> &res)
    {
        if (!curr or board[x][y] == '#')
            return;

        if (curr->isEndOfWord)
            res.insert(curr->word);

        char c = board[x][y];
        board[x][y] = '#';
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY, N, M) and board[newX][newY] != '#')
                dfs(board, curr->children[board[newX][newY]], newX, newY, N, M, res);
        }
        board[x][y] = c;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        root = new Trie();
        for (auto &word : words)
            add(word);

        int N = board.size(), M = N ? board[0].size() : 0;
        if (N == 0 or M == 0)
            return {};

        unordered_set<string> ans;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (root->children.count(board[i][j]))
                    dfs(board, root->children[board[i][j]], i, j, N, M, ans);

        vector<string> finalAns;
        for (auto &s : ans)
            finalAns.push_back(s);
        return finalAns;
    }
};