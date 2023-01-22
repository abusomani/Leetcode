/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
int MAX_LEN = 6;
class Solution {
private:
    int matchWord(string a, string b){
        int N = a.size(),cnt = 0;
        for(int i=0; i<N; i++)
            if(a[i] == b[i])
                cnt++;
        return cnt;
    }
    // pre-process
    map<pair<string,string>, int> MatchResult;
    void computeMatch(vector<string> &V){
        for(auto &s: V){
            for(auto &str: V)
                MatchResult[{s, str}] = matchWord(s, str);
        }
    }
    void computeScore(vector<string> &V, unordered_map<string, int> &Score){
        for(auto &s : V)
            for(auto &i: V)
                Score[s] += MatchResult[{s, i}];
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        computeMatch(wordlist);
        
        vector<string> guesses(wordlist.begin(), wordlist.end());
        for(int i=0; i<10; i++){
            unordered_map<string,int> Score;
            computeScore(guesses, Score);
            
            int mx = -1;
            string guess;
            for(auto &p : Score)
                if(p.second > mx)
                {
                    mx = p.second;
                    guess = p.first;
                }
            
            int value = master.guess(guess);
            vector<string> newList;
            for(auto &s: guesses){
                if(MatchResult[{guess, s}] == value)
                    newList.push_back(s);
            }
            guesses = newList;
        }
    }
};
// Always choose the most likely one. Compute similarity and choose the best one.
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution
{
private:
    int matchWord(string a, string b)
    {
        int N = a.size(), res = 0;
        for (int i = 0; i < N; i++)
            res += (a[i] == b[i]);
        return res;
    }

public:
    void findSecretWord(vector<string> &wordlist, Master &master)
    {
        for (int i = 0; i < 10; i++)
        {
            unordered_map<string, int> Score;
            for (auto &word1 : wordlist)
                for (auto &word2 : wordlist)
                    Score[word1] += matchWord(word1, word2);

            pair<string, int> minimax = {"", INT_MIN};
            for (auto &p : Score)
                if (p.second > minimax.second)
                    minimax = p;

            int value = master.guess(minimax.first);
            vector<string> newList;
            for (auto &s : wordlist)
                if (matchWord(minimax.first, s) == value)
                    newList.push_back(s);
            wordlist = newList;
        }
    }
};