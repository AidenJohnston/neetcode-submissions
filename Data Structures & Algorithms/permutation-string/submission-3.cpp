class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string sorted = s1;
        sort(sorted.begin(), sorted.end());

        if (s2.length() < s1.length()) {
            return false;
        }

        for (int x = 0; x <= (s2.length() - s1.length()); ++x) {
            string currentWindow = s2.substr(x, s1.length());
            sort(currentWindow.begin(), currentWindow.end());
            if (currentWindow == sorted) {
                return true;
            }
        }
        
        return false;
    }
};
