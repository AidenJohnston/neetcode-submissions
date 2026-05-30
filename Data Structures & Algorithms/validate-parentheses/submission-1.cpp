class Solution {
public:
    bool isValid(string s) {
        vector<char> char_vector(s.begin(), s.end());     
        stack<char> brackets;

        for (int x = 0; x < s.length(); x++) {
            char current = s[x];
            if (current == '(' || current == '{' || current == '[' ) {
                brackets.push(current);
            }
            else {
                if (brackets.empty()) return false;

                if (current == ')' && brackets.top() != '(') return false;
                if (current == '}' && brackets.top() != '{') return false;
                if (current == ']' && brackets.top() != '[') return false;

                brackets.pop();
            }
        }
        return brackets.empty();
    }
};
