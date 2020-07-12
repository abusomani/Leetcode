/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
 * The question is unclear. For example, if we did not have nodes 7 and 4, the answer would
 * be TreeNode(3). If we did not have node 4, the answer would be TreeNode(7) and not
 * TreeNode(2). Similarly, if we did not have 7, the answer would be TreeNode(4) and not
 * TreeNode(2).
 *
 * Intuitively, we should be traversing from the children to the parent and calculate the
 * height from bottom. So the null nodes would have height 0. The leaf nodes would have the
 * height 1 and the root would have the max height.
 
 * At each node, we keep a pair<node, height_of_node_from_bottom>. At a given node, if we
 * realize that the leftHeight == rightHeight, it means we have found the deepest subtree
 * rooted at node. If leftHeight > rightHeight, it means the deepest subtree must be rooted
 * at left child. If rightHeight > leftHeight, it means the deepest subtree must be rooted
 * at right child.
 
 * Which traversal allows us to traverse from bottom-up? Postorder! So we use it in the code.
 */
class Solution
{
public:
    pair<TreeNode *, int> lca(TreeNode *root)
    {
        if (!root)
            return {nullptr, 0};
        auto left = lca(root->left);
        auto right = lca(root->right);
        if (left.second < right.second)
            return {right.first, right.second + 1};
        else if (left.second > right.second)
            return {left.first, left.second + 1};
        return {root, 1 + max(left.second, right.second)};
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return lca(root).first;
    }
};