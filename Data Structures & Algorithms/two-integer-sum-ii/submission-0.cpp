class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices;
        for (int x = 0; x < numbers.size(); x++) {
            for (int y = x; y < numbers.size(); y++) {
                if ((numbers.at(x) + numbers.at(y) == target) && (x != y)) {
                    indices.push_back(x+1);
                    indices.push_back(y+1);
                }
            }
        }
        return indices;
    }
};
