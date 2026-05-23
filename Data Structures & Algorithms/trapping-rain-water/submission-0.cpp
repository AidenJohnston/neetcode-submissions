class Solution {
public:
    int trap(vector<int>& height) {
        int left {0};
        int right {static_cast<int>(height.size()-1)};

        int leftMax {0};
        int rightMax {0};
        int totalWater {0};

        while (left < right) {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);

            if (leftMax < rightMax) {
                totalWater += leftMax - height[left];
                left++;
            }
            else {
                totalWater += rightMax - height[right];
                right--;
            }
        }
        
        return totalWater;

    }
};
