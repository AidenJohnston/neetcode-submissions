class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        std::sort(nums.begin(), nums.end());

        for (int x = 0; x < nums.size() - 2; x++) {

            if (x > 0 && nums[x] == nums[x-1]) continue;

            int left = x + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[x] + nums[left] + nums[right];

                if (sum == 0) {
                    triplets.push_back({nums[x], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }

                else if (sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }

        }
        return triplets;
    }
};
