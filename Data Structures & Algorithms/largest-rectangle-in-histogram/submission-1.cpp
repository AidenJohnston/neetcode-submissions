class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n {static_cast<int>(heights.size())};
        std::stack<int> indices;
        int maxArea {0};
        for (int x = 0; x <= n; x++) {
            int currentHeight = (x == n) ? 0 : heights[x];
            while (!indices.empty() && heights[indices.top()] > currentHeight) {
                int poppedIndex = indices.top();
                indices.pop();      
                int height = heights[poppedIndex];
                int width = indices.empty() ? x : (x - indices.top() - 1);
                maxArea = std::max(maxArea, height * width);
            }
            indices.push(x);
        }
        return maxArea;
    }
};
