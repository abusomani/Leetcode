class Solution {
public:
    string getHint(string secret, string guess) {
        int cow = 0, bull = 0, N = secret.size();
        unordered_multiset<char> cowSet;
        for(int i=0; i<N; i++)
        {
            if(secret[i] == guess[i])bull++;
            else
                cowSet.insert(guess[i]);
        }
        for(int i=0; i<N; i++)
            if(secret[i] != guess[i] and cowSet.count(secret[i]))
                cow++, cowSet.erase(cowSet.find(secret[i]));
        return to_string(bull) + "A" + to_string(cow) + "B";      
    }
};