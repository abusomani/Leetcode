const int N = 2, M = 3;
class Solution
{
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<int>> finalBoard;
    string finalBoardString;
    bool isValid(int i, int j)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    string boardToString(vector<vector<int>> &board)
    {
        string boardString = "";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                boardString += to_string(board[i][j]) + "#";
        return boardString;
    }
    pair<int, int> findZeroInBoard(vector<vector<int>> &board)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == 0)
                    return {i, j};
        return {-1, -1};
    }
    vector<vector<vector<int>>> getNewBoards(
        vector<vector<int>> &board, unordered_set<string> &visited)
    {
        vector<vector<vector<int>>> result;
        pair<int, int> P = findZeroInBoard(board);
        for (int dir = 0; dir < 4; dir++)
        {
            int newX = P.first + dx[dir];
            int newY = P.second + dy[dir];
            if (isValid(newX, newY))
            {
                vector<vector<int>> V = board;
                swap(V[newX][newY], V[P.first][P.second]);
                if (!visited.count(boardToString(V)))
                    result.push_back(V);
            }
        }
        return result;
    }

public:
    void init()
    {
        finalBoard = {{1, 2, 3}, {4, 5, 0}};
        finalBoardString = boardToString(finalBoard);
    }
    int BFS(vector<vector<int>> &board)
    {
        int level = 0;
        unordered_set<string> visited;
        queue<vector<vector<int>>> Q;
        Q.push(board);
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                auto V = Q.front();
                Q.pop();

                string presentBoard = boardToString(V);
                visited.insert(presentBoard);
                if (presentBoard == finalBoardString)
                    return level;

                for (auto &b : getNewBoards(V, visited))
                {
                    string boardStr = boardToString(b);
                    if (boardStr == finalBoardString)
                        return level + 1;
                    // insert into visited at that time, so that same level dont have repeated states of board
                    visited.insert(boardStr);
                    Q.push(b);
                }
            }
            level++;
        }

        return -1;
    }
    int slidingPuzzle(vector<vector<int>> &board)
    {
        init();
        return BFS(board);
    }

    int slidingPuzzleShort(vector<vector<int>> &b)
    {
        string target = "123450",
               begin = to_string(b[0][0]) + to_string(b[0][1]) + to_string(b[0][2]) + to_string(b[1][0]) + to_string(b[1][1]) + to_string(b[1][2]);
        vector<vector<int>> nextMoves{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_set<string> visited{begin};
        queue<string> q;
        q.push(begin);
        for (int depth = 0; !q.empty(); ++depth)
        {
            int size = (int)q.size();
            for (int i = 0; i < size; ++i)
            {
                auto curr = q.front();
                q.pop();
                if (curr == target)
                    return depth;
                int zero = (int)curr.find("0");
                for (auto next : nextMoves[zero])
                {
                    auto candidate = curr;
                    swap(candidate[zero], candidate[next]);
                    if (visited.find(candidate) == visited.end())
                    {
                        visited.insert(candidate);
                        q.push(candidate);
                    }
                }
            }
        }
        return -1;
    }
};