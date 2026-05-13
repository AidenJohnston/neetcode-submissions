class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for (const string& s : strs) {
            encoded_string += to_string(s.length()) + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.length()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            decoded.push_back(s.substr(i, length));
            i += length;
        }
        return decoded;
    }
};
