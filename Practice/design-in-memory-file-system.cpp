struct Node{
    unordered_map<string, Node*> children;
    bool isFile;
    string content;
    Node(): isFile(false), content(""){}
};
class FileSystem {
private:
    Node *root;
    Node* goToPath(string path){
        Node *curr = root;
        stringstream ss(path);
        string tmp;
        while(getline(ss, tmp, '/')){
            if(tmp.empty())continue;
            if(!curr->children.count(tmp))
                curr->children[tmp] = new Node();
            curr = curr->children[tmp];
        }
        return curr;
    }
public:  
    FileSystem(){
        root = new Node();
    }
    
    vector<string> ls(string path){
        vector<string> res;
        Node *curr = root;
        stringstream ss(path);
        string tmp;
        while(getline(ss, tmp, '/')){
            if(tmp.empty())continue;
            if(!curr->children.count(tmp))
                return res; // Empty array
            else
                curr = curr->children[tmp];
        }
        if(curr->isFile)
            return {path.substr(path.find_last_of('/')+1)};
        for(auto p: curr->children)
            res.push_back(p.first);
        // lexicographically sorted
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path){
        goToPath(path);
    }
    
    void addContentToFile(string filePath, string content){
        Node *curr = goToPath(filePath);
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath){
        Node *curr = root;
        stringstream ss(filePath);
        string tmp;
        while(getline(ss, tmp, '/')){
            if(tmp.empty())continue;
            // Path invalid
            if(!curr->children.count(tmp))
                return "";
            curr = curr->children[tmp];
        }
        return curr->content;
    }
};