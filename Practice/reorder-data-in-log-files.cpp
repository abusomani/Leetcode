class Solution {
private:
    bool isDigitLog(string log){
        string id;
        int N = log.size();
        bool spaceFound = false;
        for(int i=0; i<N; i++)
        {
            if(log[i] == ' ')
            {
                spaceFound = true;
                continue;
            }
            if(!spaceFound)
                id += log[i];
            else
                return isdigit(log[i]);
        }
        return false;
    }
    pair<string,string> transform(string log){
        int N = log.size();
        string id , content;
        bool spaceFound = false;
        for(int i=0; i<N; i++)
        {
            if(log[i] == ' ')
                spaceFound = true;
            if(!spaceFound)
                id += log[i];
            else
                content += log[i];
        }
        return {content, content + id};
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<pair<string, string>,string>> letters;
        vector<string> digits;
        
        for(auto &log: logs)
        {
            if(isDigitLog(log))
                digits.push_back(log);
            else
                letters.push_back({transform(log), log});
        }
        sort(letters.begin(), letters.end());
        vector<string> res;
        for(auto &l : letters)
            res.push_back(l.second);
        for(auto &d: digits)
            res.push_back(d);
        return res;
    }
};