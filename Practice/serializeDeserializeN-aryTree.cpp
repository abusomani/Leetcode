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

private:
    void serialize(Node *root, ostringstream &out)
    {
        if (!root)
            out << "# ";
        else
        {
            int N = root->children.size();
            out << root->val << " " << N << " ";
            for (auto i : root->children)
                serialize(i, out);
        }
    }

    Node *deserialize(istringstream &in)
    {
        string val, size;
        in >> val;
        if (val == "#")
            return NULL;

        in >> size;
        Node *root = new Node(stoi(val), {});
        int N = stoi(size);
        for (int i = 0; i < N; i++)
            root->children.push_back(deserialize(in));

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));