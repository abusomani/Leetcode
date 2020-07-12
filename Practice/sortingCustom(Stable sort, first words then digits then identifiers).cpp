class Solution {
public:
    static bool myCompare(string a, string b){
        int i = a.find(' ');
        int j = b.find(' ');
        if(isdigit(a[i + 1]))
            if(isdigit(b[j + 1]))
                return false;       // a b are both digit logs, a == b, keep their original order
            else
                return false;       // a is digit log, b is letter log, a > b
        else
            if(isdigit(b[j + 1]))
                return true;        // a is letter log, b is digit log, a < b
            else {
                if (a.substr(i) == b.substr(j))
                    return a.substr(0,i) < b.substr(0,j); //If string part is the same, compare key
                else
                    return a.substr(i) < b.substr(j);   // a and b are both letter
            }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), myCompare);
        return logs;
    }
};