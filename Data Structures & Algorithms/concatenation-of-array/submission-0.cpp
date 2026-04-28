class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int length = nums.size();
        cout << length << endl;
        vector<int> ans;
        for (int x = 0; x < length; x++) {
            ans.push_back(nums.at(x));
        }
        for (int x = 0; x < length; x++) {
            ans.push_back(nums.at(x));
        }
        return ans;
    }
};