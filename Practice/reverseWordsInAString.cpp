class Solution
{
public:
    string reverseWords(string str)
    {
        string answer, tmp;
        reverse(str.begin(), str.end());
        stringstream ss(str);
        while (getline(ss, tmp, ' '))
        {
            if (tmp == "" or tmp == " ")
                continue;
            reverse(tmp.begin(), tmp.end());
            answer += tmp + " ";
        }
        if (answer.size() > 0)
            answer.pop_back();
        return answer;
    }
};