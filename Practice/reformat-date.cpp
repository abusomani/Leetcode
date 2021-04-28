class Solution {
private:
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string findMonth(string key){
        for(int i=1; i<=12; i++)
            if(months[i-1] == key)
            {
                if(i < 10)
                    return "0"+to_string(i);
                return to_string(i);
            }
        return "";
    }
    string findDate(string s){
        string res;
        for(int i=0; i<s.size() and isdigit(s[i]); i++)
            res += s[i];
        return res.size() == 1 ? "0" + res : res;
    }
public:
    string reformatDate(string date) {
        string res, tmp;
        stringstream ss(date);
        vector<string> parts;
        while(getline(ss, tmp, ' '))
            parts.push_back(tmp);
        res += parts.back() + "-" + findMonth(parts[1]) + "-" + findDate(parts[0]);
        return res;
    }
};