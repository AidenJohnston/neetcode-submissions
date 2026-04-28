class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ref;
        for (int x = 0; x < nums.size(); x++) {
            int diff = target - nums[x];

            if (ref.find(diff) != ref.end()) {
                return {ref[diff], x};
            }

            ref[nums[x]] = x;
        }
        return {};
    }
};
