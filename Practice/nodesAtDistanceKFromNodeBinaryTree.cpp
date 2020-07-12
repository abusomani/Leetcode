/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> parent;
    void createParentNode(TreeNode *root)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            Q.pop();

            if (node->left)
            {
                parent[node->left] = node;
                Q.push(node->left);
            }

            if (node->right)
            {
                parent[node->right] = node;
                Q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        if (root == NULL)
            return vector<int>();
        createParentNode(root);

        vector<int> ans;
        //BFS
        queue<pair<TreeNode *, int>> Q;
        Q.push(make_pair(target, K));
        unordered_map<TreeNode *, bool> visited;
        visited[target] = true;

        while (!Q.empty())
        {
            pair<TreeNode *, int> P = Q.front();
            Q.pop();
            TreeNode *node = P.first;
            if (P.second == 0)
                ans.push_back(node->val);

            if (node->left and visited.find(node->left) == visited.end())
            {
                Q.push(make_pair(node->left, P.second - 1));
                visited[node->left] = true;
            }

            if (node->right and visited.find(node->right) == visited.end())
            {
                Q.push(make_pair(node->right, P.second - 1));
                visited[node->right] = true;
            }

            // parent
            if (parent.find(node) != parent.end() and visited.find(parent[node]) == visited.end())
            {
                Q.push(make_pair(parent[node], P.second - 1));
                visited[parent[node]] = true;
            }
        }

        return ans;
    }
};