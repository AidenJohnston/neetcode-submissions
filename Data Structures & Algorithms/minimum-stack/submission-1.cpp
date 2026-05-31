class MinStack {
private:
    // pair.first = value, pair.second = min value at this state
    vector<pair<int, int>> st;

public:
    MinStack() {
        // Fast I/O trick
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // Optional: Pre-allocate memory to prevent dynamic resizing overhead
        st.reserve(30000); 
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push_back({val, val});
        } else {
            // Compare current val with the minimum of the previous element
            st.push_back({val, min(val, st.back().second)});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};
