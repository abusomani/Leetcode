class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int N = s.size();
        if(k > N)return false;
        unordered_set<int> St;
        int num = 0, cnt = 0;
        for(int i=N-1; i>N-k-1; i--)
            num = num + (s[i] == '1' ? (1<<cnt) : 0), cnt++;
        cnt--;
        St.insert(num);
        int j=N-k-1;
        while(j >= 0)
            num -= (s[j+k]-'0'), num /= 2, num += s[j] == '1' ? (1<<cnt) : 0, St.insert(num),j--;
        int total = (1 << k);
        for(int i=0; i<total; i++)
            if(!St.count(i))
                return false;
        return true;
    }
};