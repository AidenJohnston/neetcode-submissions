class MinStack {
private:
    vector<int> minStack;
    vector<int> minValues;

public:
    MinStack() {minValues.push_back(INT_MAX);}
    
    void push(int val) {
        minStack.push_back(val);
        if (val <= minValues.back()) {
            minValues.push_back(val);
        }
    }
    
    void pop() {
        if (minValues.back() == minStack.back()) {
            minValues.pop_back();
        }
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        return minValues.back();
    }
};
