class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int x = 0; x < nums.size(); x++) {
            counts[nums.at(x)]++;
        }

        vector<int> frequent;
        for (int x = 0; x < k; x++) {
            
            auto max_it = max_element(counts.begin(), counts.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second;
            });

            frequent.push_back(max_it->first);
            counts.erase(max_it);
        }
        return frequent;
    }
};
