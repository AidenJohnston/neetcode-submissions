class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> timeMap;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        
        if (timeMap.find(key) != timeMap.end()) {
            vector<pair<int, string>> copy = timeMap[key];

            if (copy[0].first > timestamp) {
                return "";
            }

            int best_idx {0};
            int left {0};
            int right {static_cast<int>(copy.size() - 1)};
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (copy[mid].first <= timestamp) {
                    best_idx = mid;
                }
                
                if (timestamp > copy[left].first) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            return copy[best_idx].second;
        }
        return "";
    }
};
