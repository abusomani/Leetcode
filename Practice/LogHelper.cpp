#include <bits/stdc++.h>
#include <unordered_map>
#include <filesystem>
#include <ctime>
using namespace std;

const string START_EVENT = "**START**";
const string END_EVENT = "**END**";
const string FILE_DELIM = "_";
const string OUTPUT_DIR = "./formatted-log-files/";

class ThreadInfo {
public:
    string threadId;
    string threadName;
    string timestamp;
    string message;
    void getThreadInfoUtil(vector<string> logParts)
    {
        // first part is always the threadId
        threadId = logParts.front();
        threadName = threadId.substr(threadId.find("::")+2);
        timestamp = logParts[1] + " " + logParts[2];
        for(int i=3; i<logParts.size(); i++)
            message += logParts[i] + " ";
        if(!message.empty())
            message.pop_back();
    }

    ThreadInfo() {};
    ThreadInfo(string log){
        getThreadInfo(log);
    }
    void getThreadInfo(string log)
    {
        vector<string> logParts;
        string tmp;
        stringstream ss(log);
        while (getline(ss, tmp, ' '))
        {
            if (tmp.empty())
                continue;

            logParts.push_back(tmp);
        }
        getThreadInfoUtil(logParts);
    }
    friend ostream &operator<<(ostream &os, const ThreadInfo &th);
};

ostream &operator<<(ostream &os, const ThreadInfo &th)
{
    os << th.threadId << " " << th.timestamp << " " << th.message <<endl;
    return os;
}

class LogSanitizer {
private:
    // Map from thread id to a pair of ofstream pointer and file-name
    unordered_map<string, pair<ofstream*, string>> thread_to_file;
    string getFileName(const ThreadInfo &th){
        return OUTPUT_DIR + th.threadName + FILE_DELIM + th.timestamp;
    }
    void writeToFile(string log, const ThreadInfo &th){
        if (thread_to_file.count(th.threadName))
        {
            (*thread_to_file[th.threadName].first) << log << endl;
            // flush required to retain the buffer and not getting destroyed.
            (*thread_to_file[th.threadName].first).flush();
        }
    }

public:
    void sanitize(string filePath) {
        /*
            std::map<std::string, std::ofstream> can't possibly work, because std::map requires its data type to be Assignable, which std::ofstream isn't. 
            In the alternative, the data type must be a pointer to ofstream -- either a raw pointer or a smart pointer.
        */
        string log;

        ifstream infile(filePath, ifstream::in);
        while(infile.good()){
            getline(infile, log);

            ThreadInfo th(log);
            if(th.message.find(START_EVENT) != string::npos){
                string fileName = getFileName(th);
                thread_to_file[th.threadName] = {new ofstream(fileName, ofstream::out | ofstream::app), fileName};
            } 
            else if(th.message.find(END_EVENT) != string::npos) {
                writeToFile(log, th);
                string oldFileName = thread_to_file[th.threadName].second;
                string newFileName = oldFileName + FILE_DELIM + th.timestamp;
                filesystem::rename(oldFileName, newFileName);
                (*thread_to_file[th.threadName].first).close();
                continue;
            }
            writeToFile(log, th);
        }
    }

    void cleanSanitizedFiles(string dir_path = OUTPUT_DIR) {
        for (const auto &entry : filesystem::directory_iterator(dir_path))
            filesystem::remove_all(entry.path());
    }
};

/**
 *  Enhance this utils to take care of different time formats.
 *  Currently supports only till seconds and not milliseconds. 
 */
class TimeUtils
{
public:
    static std::string getTimeStamp(time_t epochTime, const char *format = "%Y-%m-%d %H:%M:%S,%J")
    {
        char timestamp[64] = {0};
        strftime(timestamp, sizeof(timestamp), format, localtime(&epochTime));
        return timestamp;
    }

    static time_t convertTimeToEpoch(const char *theTime, const char *format = "%Y-%m-%d %H:%M:%S,%J")
    {
        std::tm tmTime;
        memset(&tmTime, 0, sizeof(tmTime));
        strptime(theTime, format, &tmTime);
        return mktime(&tmTime);
    }
};

vector<string> loopSanitizedFiles(string dir_path = OUTPUT_DIR)
{
    vector<string> files;
    for (const auto &entry : filesystem::directory_iterator(dir_path))
        files.push_back(entry.path());

    return files;
}

pair<string, string> getTimestamps(string fileName)
{
    pair<string, string> P = {"", ""};
    stringstream ss(fileName);
    string tmp;
    while (getline(ss, tmp, '_'))
    {
        if (!tmp.empty() and isdigit(tmp[0]))
        {
            P.second = tmp;
            if (P.first.empty())
                P.first = tmp;
        }
    }
    return P;
}

vector<string> getFileReference(string t1, string t2, bool showFileNames){

    auto isOverlapping = [&](string t1, string t2, pair<string, string> range){
        bool doNotOverlap = t1 > range.second or t2 < range.first;
        return !doNotOverlap;
    };

    vector<string> result;
    vector<string> files = loopSanitizedFiles();
    for (auto file : files) {
        if(isOverlapping(t1, t2, getTimestamps(file)))
            result.push_back(file);
            if(showFileNames)
                cout << file << endl;
    }
    return result;
}

void getFileReference(string t1, string t2)
{
    vector<string> files = getFileReference(t1, t2, false);
    for(auto file: files) {
        fstream f(file, fstream::in);
        string line;
        while(getline(f, line))
            cout<<line<<endl;
        f.close();
    }
}

int main(int argc, char **args) {
    //Getting input from user
    // for(int i=0; i<argc; i++)
    //     cout << args[i] << endl;

    LogSanitizer logSanitizer;
    logSanitizer.sanitize("./log-files/log1.txt");
    cout << TimeUtils::convertTimeToEpoch("2020-08-09 18:59:25,237");
    // getFileReference("2020-08-09 18:59:25", "2020-08-09 18:59:25,263", true);
    logSanitizer.cleanSanitizedFiles();
}