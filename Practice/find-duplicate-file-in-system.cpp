class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> Mp;
        for(auto path: paths){
            stringstream ss(path);
            string tmp;
            vector<string> V;
            while(getline(ss, tmp, ' '))
                V.push_back(tmp);
            for(int i=1; i<V.size(); i++){
                int open = V[i].find('(');
                string fn = V[i].substr(0, open), 
                       content = V[i].substr(open);
                Mp[content].push_back(V[0]+"/"+fn);
            }
        }
        vector<vector<string>> res;
        for(auto p: Mp)
            if(p.second.size()>1) // only if duplicate are found
                res.push_back(p.second);
        return res;
    }
};