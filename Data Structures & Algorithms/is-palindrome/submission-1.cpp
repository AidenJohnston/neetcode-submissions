class Solution {
public:
    bool isPalindrome(string s) {
        string copy {s};
        
        transform(copy.begin(), copy.end(), copy.begin(),
                    [](unsigned char c) { return tolower(c); });
        
        copy.erase(std::remove_if(copy.begin(), copy.end(), [](unsigned char c) {
            return !isalnum(c);
        }), copy.end());

        cout << copy;

        int x {0};
        int y {static_cast<int>(copy.length()-1)};

        while (x < y) {
            if (copy.at(x) == copy.at(y)) {
                x++;
                y--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
