class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left {0};
        int right {static_cast<int>(heights.size()-1)};

        int maxWater = 0;

        while (left < right) {
            int currentWater = min(heights[left], heights[right]) * (right-left);

            maxWater = max(maxWater, currentWater);

            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxWater;
    }
};
