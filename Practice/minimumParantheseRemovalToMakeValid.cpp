class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        int N = s.size();
        for (int i = 0; i < N; i++)
        {
            char c = s[i];
            if (c == '(')
                st.push(i);
            else if (c == ')')
            {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = '*';
            }
        }

        while (!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }

        string result = "";
        for (int i = 0; i < N; i++)
            if (s[i] != '*')
                result += s[i];

        return result;
    }
};