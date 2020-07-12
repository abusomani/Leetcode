typedef long long ll;
class Solution {
public:
    unordered_map<char,ll> Mp;
    string frequencySort(string s) {
        Mp.clear();
        for(char c : s)
            Mp[c]++;
        
        sort(s.begin(),s.end(),[this](const char a,const char b){
            return (Mp[a] == Mp[b]) ? (a > b) : (Mp[a] > Mp[b]);
        });
        return s;
    }
};