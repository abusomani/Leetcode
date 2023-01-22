/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec
{
private:
    void serialize(Node *root, ostringstream &out)
    {
        if (root == nullptr)
            out << "# ";
        else
        {
            // value + " " + children.size() + " "
            out << to_string(root->val) + " " + to_string(root->children.size()) + " ";
            for (auto &child : root->children)
                serialize(child, out);
        }
    }
    Node *deserialize(istringstream &in)
    {
        string tmp, childSize;
        getline(in, tmp, ' ');
        if (tmp == "#")
            return nullptr;
        // sure that childrenSize would be there
        getline(in, childSize, ' ');
        vector<Node *> children(stoi(childSize), nullptr);
        Node *root = new Node(stoi(tmp), children);
        for (int i = 0; i < children.size(); i++)
            root->children[i] = deserialize(in);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));