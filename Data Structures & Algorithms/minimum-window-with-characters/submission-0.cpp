class Solution {
public:
    string minWindow(string s, string t) {
        int sLength {static_cast<int>(s.length())};
        int tLength {static_cast<int>(t.length())};

        if (tLength > sLength) return "";

        vector<int> tFreq(128, 0);
        vector<int> windowFreq(128, 0);

        for (char c : t) {
            tFreq[c]++;
        }

        int required {0};
        for (int count : tFreq) {
            if (count > 0) required++;
        }

        int left {0};
        int formed {0};
        int minLen = {INT_MAX};
        int startIdx {0};

        for (int right = 0; right < sLength; right++) {
            char rightChar = s[right];
            windowFreq[rightChar]++;

            if (tFreq[rightChar] > 0 && windowFreq[rightChar] == tFreq[rightChar]) {
                formed++;
            }

            while (formed == required) {
                
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar {s[left]};
                windowFreq[leftChar]--;

                if (tFreq[leftChar] > 0 && windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);

    }
};
