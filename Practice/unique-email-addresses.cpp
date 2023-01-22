class Solution {
private:
    string massage(string email){
        bool atFound = false, plusFound = false;
        string res;
        for(auto &c: email){
            if(atFound){
                res += c;
                continue;
            }
            else if(c == '@') {
                res += c;
                atFound = true;
            }
            else if(c == '+') {
                plusFound = true;
            }
            else if(c == '.')
                continue;
            else if(!plusFound)
                res += c;
        }
        return res;
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> Emails;
        for(auto &email: emails)
            Emails.insert(massage(email));
        return (int)Emails.size();
    }
};