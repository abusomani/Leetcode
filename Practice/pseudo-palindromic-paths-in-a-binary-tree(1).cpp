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
    int res = 0;
    bool canFormPalindrome(vector<int> V){
        unordered_map<int,int> Mp;
        for(auto &i: V)Mp[i]++;
        int oddCnt = 0;
        for(auto &i : Mp)
            if(i.second & 1)
                oddCnt ++;
        return oddCnt <= 1;
    }
public:
    void allPaths(TreeNode *root, vector<int> &path) {
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left and !root->right) {
            if(canFormPalindrome(path))
                res++;
        }
        allPaths(root->left, path);
        allPaths(root->right, path);
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> V;
        allPaths(root, V);
        return res;
    }
};