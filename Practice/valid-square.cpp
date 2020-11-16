#define ll long long
class Solution {
public:
    ll distance(vector<int> &a, vector<int> &b) {
        return (a[0]-b[0]) * (a[0]-b[0]) + (a[1]-b[1]) * (a[1]-b[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<ll,int> Mp;
        vector<vector<int>> V;
        V.push_back(p1);V.push_back(p2);V.push_back(p3);V.push_back(p4);
        for(int i=0; i<4; i++) 
            for(int j=i+1; j<4; j++)
                Mp[distance(V[i], V[j])];
        if(Mp.size() != 2)return false;
        ll a = -1 , c = -1;
        for(auto &i : Mp)
        {
            if(a == -1)
                a = i.first;
            else
                c = i.first;
        }
        if(a > c) // because unordered_map, not sorted
            swap(a, c);
        return a + a == c;
    }
};