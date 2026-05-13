class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for (int x = 0; x < strs.size(); x++) {
            int size = strs.at(x).length();
            string append = to_string(size) + "#" + strs.at(x);
            encoded_string.append(append);
        }
        cout << encoded_string << endl;
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
