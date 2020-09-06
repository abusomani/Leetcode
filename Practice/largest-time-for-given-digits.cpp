class Solution {
public:
    bool isValid(string &s)
    {
        int hour = stoi(s.substr(0,2));
        int mins = stoi(s.substr(2));
        return (hour >= 0 and hour <= 23 and mins >= 0 and mins <= 59);
    }
    string largestTimeFromDigits(vector<int>& A) {
        string s;
        for(auto &i: A)
            s += to_string(i);
        sort(s.begin(), s.end());
        vector<string> perms;
        while(true)
        {
            perms.push_back(s);
            if(!next_permutation(s.begin(), s.end()))
               break;
        }
        string ans = "";
        for(auto &s : perms)
             if(isValid(s))
                 ans = s;
        
        return !ans.empty() ? ans.substr(0, 2) + ":" + ans.substr(2) : ans; 
    }
};