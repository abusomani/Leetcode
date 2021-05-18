class Solution {
private:
    enum Type {
        LEAF, PARENT, COVERED
    };
public:
    int result = 0;
    int minCameraCover(TreeNode* root) {
        auto cover = dfs(root);
        if(cover == LEAF) {
            result++;
        }
        
        return result;
    }
    
    Type dfs(TreeNode* node) {
        
        if(!node) {
            return COVERED;
        }
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        if(left == LEAF || right == LEAF) {
            result++;
            return PARENT;
        }
        
        return left == PARENT || right == PARENT ? COVERED: LEAF;
    }
};