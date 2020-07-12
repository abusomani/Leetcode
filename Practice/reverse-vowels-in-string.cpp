//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u');
    }
    string reverseVowels(string s)
    {
        vector<pair<char, int>> V; // characters from start and index from end
        for (int i = 0; i < s.size(); i++)
            if (isVowel(s[i]))
                V.push_back(make_pair(s[i], i));
        for (int i = 0; i < V.size(); i++)
            s[V[i].second] = V[V.size() - i - 1].first;

        /*
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        */

        return s;
    }
};