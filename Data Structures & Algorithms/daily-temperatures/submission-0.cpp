class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> indices;

        for (int x = 0; x < n; x++) {
            while (!indices.empty() && temperatures[x] > temperatures[indices.top()]) {
                int prevIndex = indices.top();
                indices.pop();
                result[prevIndex] = x - prevIndex;
            }
            indices.push(x);
        }
        return result;
    }
};
