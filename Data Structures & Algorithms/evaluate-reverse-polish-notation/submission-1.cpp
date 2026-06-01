class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int x = 0; x < tokens.size(); x++) {
            if (tokens[x] != "+" && tokens[x] != "-" && tokens[x] != "*" && tokens[x] != "/") {
                nums.push(stoi(tokens[x]));
            }
            else if (tokens[x] == "+") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(num1 + num2);
            }
            else if (tokens[x] == "-") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(num1 - num2);
            }
            else if (tokens[x] == "*") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(num1 * num2);
            }
            else if (tokens[x] == "/") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(num1 / num2);
            }
        }
        return nums.top();
    }
};
