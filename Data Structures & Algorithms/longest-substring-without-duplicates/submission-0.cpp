class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> counts;
        int longest {0};
        int left {0};
        for (int right = 0; right < s.length(); right++) {
            while (counts.contains(s[right])) {
                counts.erase(s[left]);
                left++;
            }
            counts.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
