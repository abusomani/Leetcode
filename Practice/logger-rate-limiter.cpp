/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
int DIFF_TIME = 10;
class Logger {
private:
    unordered_map<string,int> Logs;
public:
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(!Logs.count(message) or Logs[message] <= timestamp - DIFF_TIME)        
        {
            Logs[message] = timestamp;
            return true;
        }
        else
            return false;
    }
};