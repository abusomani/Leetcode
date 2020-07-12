/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;

        unordered_map<Node *, Node *> nodes;
        unordered_map<Node *, set<Node *>> graph;
        unordered_set<Node *> visited;
        queue<Node *> Q;
        Q.push(node);

        while (!Q.empty())
        {
            Node *src = Q.front();
            Q.pop();
            visited.insert(src);

            if (!nodes.count(src))
                nodes[src] = new Node(node->val); // replica node

            for (auto neighbor : src->neighbors)
            {
                if (!nodes.count(neighbor))
                    nodes[neighbor] = new Node(neighbor->val);

                graph[nodes[src]].insert(nodes[neighbor]);
                graph[nodes[neighbor]].insert(nodes[src]);

                if (!visited.count(neighbor))
                    Q.push(neighbor);
            }
        }

        for (auto nodes : graph)
        {
            nodes.first->neighbors = vector<Node *>(graph[nodes.first].begin(), graph[nodes.first].end());
        }

        return nodes[node];
    }
};