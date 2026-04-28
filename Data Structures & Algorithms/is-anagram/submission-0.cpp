class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};

        for (int x = 0; x < s.length(); x++) {
            count[s[x] - 'a']++;
            count[t[x] - 'a']--;
        }

        for (int x = 0; x < size(count); x++) {
            if (count[x] != 0) {
                return false;
            }
        }

        return true;
    }
};
