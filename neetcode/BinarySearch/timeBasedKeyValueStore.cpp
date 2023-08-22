#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> dict;

public:
    TimeMap() {
        // key maps to list of pair value, timestamp
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(dict[key].begin(), dict[key].end(), make_pair(timestamp, string()));

        if (it == dict[key].begin()) {
            return "";
        }

        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */