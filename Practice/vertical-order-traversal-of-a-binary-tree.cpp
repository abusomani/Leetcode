/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // sorted by x and then y coordinate
    map<int, map<int, set<int>>> Mp;
    void dfs(TreeNode* root, int x, int y) {
        if(!root) return;
        Mp[x][y].insert(root->val);
        dfs(root->left, x-1, y+1);
        dfs(root->right, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,0,0);
        for(auto &row : Mp) {
            vector<int> heights;
            for(auto &col : row.second) {
                for(auto &i: col.second)
                    heights.push_back(i);
            }
            res.push_back(heights);
        }
        return res;
    }
};