class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> productExceptSelf;
        for (int x = 0; x < size; x++) {
            int product = 1;
            for (int y = 0; y < size; y++) {
                if (y != x) {
                    product = product * nums.at(y);
                }
            }
            productExceptSelf.push_back(product);
        }
        return productExceptSelf;
    }
};
