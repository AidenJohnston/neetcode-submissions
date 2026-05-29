class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max;
        for (int x = 0; x <= nums.size() - k; x++) {
            vector<int> window(nums.begin() + x, nums.begin() + x + k);
            max.push_back(*max_element(window.begin(), window.end()));
        }
        return max;
    }
};
