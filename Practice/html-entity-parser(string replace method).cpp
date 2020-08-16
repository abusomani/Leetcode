class Solution
{
private:
    string replaceString(string subject, const string &search, const string &replace)
    {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != string::npos)
        {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        return subject;
    }

public:
    string entityParser(string text)
    {
        text = replaceString(text, "&quot;", "\"");
        text = replaceString(text, "&apos;", "\'");
        text = replaceString(text, "&gt;", ">");
        text = replaceString(text, "&lt;", "<");
        text = replaceString(text, "&frasl;", "/");
        text = replaceString(text, "&amp;", "&"); // last, else it will kind of recur for cases like "&amp;gt;"
        return text;
    }
};