class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> check;
        for (int x = 0; x < size; x++) {
            if (check.count(nums.at(x))) {
                return true;
            }
            check.insert(nums.at(x));
        }
        return false;
    }
};