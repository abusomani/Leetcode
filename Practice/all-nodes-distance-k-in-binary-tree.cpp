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
private:
    unordered_map<TreeNode *, TreeNode *> parent;

public:
    void dfs(TreeNode *root, TreeNode *p = nullptr)
    {
        if (!root)
            return;
        parent[root] = p;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        vector<int> res;
        if (!target)
            return res;

        dfs(root);

        queue<TreeNode *> Q;
        unordered_set<TreeNode *> visited;

        Q.push(target);
        visited.insert(target);
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                TreeNode *node = Q.front();
                Q.pop();

                if (K == 0)
                    res.push_back(node->val);

                if (node->left and !visited.count(node->left))
                    Q.push(node->left), visited.insert(node->left);

                if (node->right and !visited.count(node->right))
                    Q.push(node->right), visited.insert(node->right);

                if (parent[node] != nullptr and !visited.count(parent[node]))
                    Q.push(parent[node]), visited.insert(parent[node]);
            }
            K--;
            if (K < 0)
                break;
        }
        return res;
    }
};