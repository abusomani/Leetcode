class Solution {
public:
// no invalid mapping for same character
// atleast one unused character in str2 to use as temp variable for breaking cycles if any.
    bool canConvert(string str1, string str2) {
        if(str1 == str2)
            return true;
        int N = str1.size();
        unordered_map<char, char> Mapping;
        for(int i=0; i<N; i++)
        {
            if(Mapping.count(str1[i]) and Mapping[str1[i]] != str2[i])return false;
            Mapping[str1[i]] = str2[i];
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};