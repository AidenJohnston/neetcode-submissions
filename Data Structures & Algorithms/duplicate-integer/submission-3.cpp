class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> duplicates;

        for (int x = 0; x < nums.size(); x++) {
            if (duplicates[nums[x]] == 1) {
                return true;
            }
            duplicates[nums[x]]++;
        }

        return false;
    }
};