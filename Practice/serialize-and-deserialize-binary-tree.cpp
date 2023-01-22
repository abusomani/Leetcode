/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (!root)
            out << "# ";
        else
        {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
    }
    TreeNode *deserialize(istringstream &in)
    {
        string tmp;
        in >> tmp;
        if (tmp == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(tmp));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));