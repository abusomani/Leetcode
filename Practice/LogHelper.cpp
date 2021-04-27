#include <bits/stdc++.h>
#include <unordered_map>
#include <filesystem>
#include <ctime>
using namespace std;

const string START_EVENT = "**START**";
const string END_EVENT = "**END**";
const string FILE_DELIM = "_";
const string INPUT_DIR = "./log-files/";
const string OUTPUT_DIR = "./formatted-log-files/";

/**
 *  Enhance this utils to take care of different time formats.
 *  Currently supports only till seconds and not milliseconds. 
 */
class TimeUtils
{
public:
    static std::string getTimeStamp(time_t epochTime, const char* format = "%Y-%m-%d %H:%M:%S,%J")
    {
        char timestamp[64] = {0};
        strftime(timestamp, sizeof(timestamp), format, localtime(&epochTime));
        return timestamp;
    }

    static long convertTimeToEpoch(const char* theTime, const char* format = "%Y-%m-%d %H:%M:%S,%J")
    {
        std::tm tmTime;
        memset(&tmTime, 0, sizeof(tmTime));
        strptime(theTime, format, &tmTime);
        return static_cast<long>(mktime(&tmTime));
    }
};

class ThreadInfo {
public:
    string threadId;
    string threadName;
    long timestamp;
    string message;
    void getThreadInfoUtil(vector<string> logParts)
    {
        // first part is always the threadId
        threadId = logParts.front();
        threadName = threadId.substr(threadId.find("::")+2);
        string timeString = logParts[1] + " " + logParts[2];
        timestamp = TimeUtils::convertTimeToEpoch(timeString.c_str());
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
        return OUTPUT_DIR + th.threadName + FILE_DELIM + to_string(th.timestamp);
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
                string newFileName = oldFileName + FILE_DELIM + to_string(th.timestamp);
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

vector<string> getAllFilesFromADirectory(string dir_path){
    vector<string> files;
    for (const auto &entry : filesystem::directory_iterator(dir_path))
        files.push_back(entry.path());

    return files;
}

vector<string> getAllSanitizedFiles(string dir_path = OUTPUT_DIR)
{
    return getAllFilesFromADirectory(dir_path);
}

pair<long, long> getTimestampsFromFileName(string fileName)
{
    pair<long, long> P = {-1, -1};
    stringstream ss(fileName);
    string tmp;
    while (getline(ss, tmp, '_'))
    {
        if (!tmp.empty() and isdigit(tmp[0]))
        {
            P.second = stol(tmp);
            if (P.first == -1)
                P.first = stol(tmp);
        }
    }
    return P;
}

vector<string> getFileReference(long t1, long t2, bool showFileNames){

    auto isOverlapping = [&](long t1, long t2, pair<long, long> range) {
        bool doNotOverlap = t1 > range.second or t2 < range.first;
        return !doNotOverlap;
    };

    vector<string> result;
    vector<string> files = getAllSanitizedFiles();
    for (auto file : files) {
        if(isOverlapping(t1, t2, getTimestampsFromFileName(file)))
            result.push_back(file);
            if(showFileNames)
                cout << file << endl;
    }
    return result;
}

void getFileReference(long t1, long t2)
{
    vector<string> files = getFileReference(t1, t2, false);
    for(auto file: files) {
        cout << "File being read is : " << file <<endl;
        fstream f(file, fstream::in);
        string line;
        while(getline(f, line))
            cout<<line<<endl;

        cout <<"---------------------------------------------------------\n";
        f.close();
    }
}

pair<long,long> secondWithMaximumConcurrentRequests(){
    map<long,long> times;
    vector<string> files = getAllSanitizedFiles();
    for(auto file: files){
        auto range = getTimestampsFromFileName(file);
        times[range.first]++;
        times[range.second+1]--;
    }
    long threads = 0, maxThreads = 0, resultSecond;
    for(auto p: times){
        threads += p.second;
        if(threads > maxThreads){
            maxThreads = threads;
            resultSecond = p.first;
        }
    }
    return {resultSecond, maxThreads};
}

long maximumNumberOfConcurrentRequests()
{
    return secondWithMaximumConcurrentRequests().second;
}

int main() {

    // pre-processing like a background job
    LogSanitizer logSanitizer;
    for (auto logFileName : getAllFilesFromADirectory(INPUT_DIR))
        logSanitizer.sanitize(logFileName);
    
    int choice;
    bool showMenu = true;
    // Mimicing a running server taking API requests.
    while (showMenu)
    {
        cout << "Enter a choice from the options\n";
        cout << "Press 1 for checking logs between timestamps t1 and t2 and see file references.\n";
        cout << "Press 2 for checking logs between timestamps t1 and t2 and see file contents.\n";
        cout << "Press 3 for seeing maximum number of concurrent requests at any given second.\n";
        cout << "Press 4 for seeing the second at which maximum number of concurrent requests happened.\n";
        cout << "Press 5 or any other number to exit the menu options.\n";

        cin >> choice;
        switch (choice) {
            case 1:
            {
                // For handling space in timestamp
                string t1, t2;
                string t3, t4;
                cout << "Enter the timestamps in the format %Y-%m-%d %H:%M:%S\n";
                cin >> t1 >> t2;
                cin >> t3 >> t4;
                getFileReference(TimeUtils::convertTimeToEpoch((t1 + " " + t2).c_str()), TimeUtils::convertTimeToEpoch((t3 + " " + t4).c_str()), true);
                break;
            };
            case 2:
            {
                // For handling space in timestamp
                string t1, t2;
                string t3, t4;
                cout << "Enter the timestamps in the format %Y-%m-%d %H:%M:%S\n";
                cin >> t1 >> t2;
                cin >> t3 >> t4;
                getFileReference(TimeUtils::convertTimeToEpoch((t1 + " " + t2).c_str()), TimeUtils::convertTimeToEpoch((t3 + " " + t4).c_str()));
                break;
            };
            case 3: {
                cout << "Maximum number of concurrent requests at any given second are : " << maximumNumberOfConcurrentRequests() << endl;
                break;
            };
            case 4:
            {
                cout << "Second at which maximum number of concurrent requests happened are : " << secondWithMaximumConcurrentRequests().first << endl;
                break;
            };
            default: {
                showMenu = false;
                break;
            }
        }
    }
    // Comment this to not delete the generated sanitized files.
    logSanitizer.cleanSanitizedFiles();
}