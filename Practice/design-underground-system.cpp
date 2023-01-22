class UndergroundSystem
{
private:
    // graph between stations, stores, the total sum of time from A -> B, with number of people contributing to it
    unordered_map<string, unordered_map<string, pair<long, int>>> stationGraph;
    // Stores the Src and startTime for each passenger
    unordered_map<int, pair<string, int>> passengers;

public:
    UndergroundSystem()
    {
        stationGraph.clear();
        passengers.clear();
    }

    void checkIn(int id, string source, int t)
    {
        passengers[id] = make_pair(source, t); // register the entry of a passenger
    }

    void checkOut(int id, string dest, int t)
    {
        string source = passengers[id].first;
        int startTime = passengers[id].second;
        // time to update the graph
        // if source is not present then first time initialize
        if (!stationGraph.count(source) or !stationGraph[source].count(dest))
            stationGraph[source][dest] = {t - startTime, 1};
        else
        {
            pair<long, int> existing = stationGraph[source][dest];
            // add new sum and increment the contributor
            stationGraph[source][dest] =
                make_pair(existing.first + (t - startTime), existing.second + 1);
        }
    }

    double getAverageTime(string src, string dest)
    {
        return stationGraph[src][dest].first / (double)stationGraph[src][dest].second;
    }
};

class UndergroundSystem1
{
public:
    unordered_map<string, pair<int, int>> checkoutMap; // Route - {TotalTime, Count}
    unordered_map<int, pair<string, int>> checkInMap;  // Uid - {StationName, Time}

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto &checkIn = checkInMap[id];
        // Nicer trick of combining the route as a key
        string route = checkIn.first + "_" + stationName;
        checkoutMap[route].first += t - checkIn.second;
        checkoutMap[route].second += 1;
    }

    double getAverageTime(string startStation, string endStation)
    {
        // find by route
        string route = startStation + "_" + endStation;
        auto &checkout = checkoutMap[route];
        return (double)checkout.first / checkout.second;
    }
};