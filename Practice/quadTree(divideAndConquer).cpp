/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution
{
private:
    Node *constructHelper(vector<vector<int>> &grid, int len, int x, int y)
    {
        int flag = grid[x][y];
        for (int i = x; i < x + len; i++)
            for (int j = y; j < y + len; j++)
                if (flag != grid[i][j]) // deeper break required
                {
                    Node *tl = constructHelper(grid, len / 2, x, y);
                    Node *tr = constructHelper(grid, len / 2, x, y + len / 2);
                    Node *bl = constructHelper(grid, len / 2, x + len / 2, y);
                    Node *br = constructHelper(grid, len / 2, x + len / 2, y + len / 2);
                    return new Node(true, false, tl, tr, bl, br);
                }

        return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return n == 0 ? NULL : constructHelper(grid, n, 0, 0);
    }
};