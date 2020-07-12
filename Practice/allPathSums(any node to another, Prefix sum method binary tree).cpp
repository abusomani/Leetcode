/*
So the idea is similar as Two sum, using HashMap to store ( key : the prefix sum, value : how many ways get to this prefix sum) , 
and whenever reach a node, we check if prefix sum - target exists in hashmap or not, 
if it does, we added up the ways of prefix sum - target into res.
*/
class Solution
{
private:
    int ans = 0;
    unordered_map<int, int> Mp;

public:
    void helper(TreeNode *root, int sum, int currSum)
    {
        if (root == nullptr)
            return;
        currSum += root->val; // root to the present node sum

        ans += Mp[currSum - sum];
        Mp[currSum]++;
        helper(root->left, sum, currSum);
        helper(root->right, sum, currSum);
        Mp[currSum]--;
    }
    int pathSum(TreeNode *root, int sum)
    {
        Mp[0] = 1;
        helper(root, sum, 0);
        return ans;
    }
};

class Solution1
{
public:
    int dfs(TreeNode *root, int sum, int currSum, unordered_map<int, int> &Mp)
    {
        if (!root)
            return 0;
        currSum += root->val;
        int res = (currSum == sum) + (Mp.count(currSum - sum) ? Mp[currSum - sum] : 0);
        Mp[currSum]++;
        res += dfs(root->left, sum, currSum, Mp);
        res += dfs(root->right, sum, currSum, Mp);
        Mp[currSum]--;

        return res;
    }
    int pathSum(TreeNode *root, int sum)
    {
        unordered_map<int, int> Mp;
        return dfs(root, sum, 0, Mp);
    }
};