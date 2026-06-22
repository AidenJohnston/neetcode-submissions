class LRUCache {
private:
    int capacity;
    std::list<pair<int, int>> l;
    std::unordered_map<int, std::list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        
        l.splice(l.begin(), l, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            l.splice(l.begin(), l, mp[key]);
        }
        else {
            if (l.size() == capacity) {
                int delete_key = l.back().first;
                mp.erase(delete_key);
                l.pop_back();
            }
            l.push_front({key, value});
            mp[key] = l.begin();
        }
    }
};
