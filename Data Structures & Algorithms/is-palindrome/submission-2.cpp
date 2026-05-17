class Solution {
public:
    bool isPalindrome(string s) {
        
        transform(s.begin(), s.end(), s.begin(),
                    [](unsigned char c) { return tolower(c); });
        
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !isalnum(c);
        }), s.end());

        int x {0};
        int y {static_cast<int>(s.length()-1)};

        while (x < y) {
            if (s.at(x) == s.at(y)) {
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
