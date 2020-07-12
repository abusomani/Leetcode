class Logger
{
private:
    unordered_map<string, int> Mp;

public:
    Logger()
    {
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        if (Mp.find(message) == Mp.end())
        {
            Mp[message] = timestamp;
            return true;
        }
        else if (timestamp - Mp[message] >= 10)
        {
            Mp[message] = timestamp;
            return true;
        }
        return false;
    }
};