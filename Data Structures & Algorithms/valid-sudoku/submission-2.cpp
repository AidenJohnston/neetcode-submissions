class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                
                int num = board[r][c] - '1';
                int b = (r / 3) * 3 + (c / 3);
                
                if (rows[r][num] || cols[c][num] || boxes[b][num]) {
                    return false;
                }
                
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[b][num] = true;
            }
        }
        return true;


        /*
        //check each row
        for (int x = 0; x < 9; x++) {
            vector<char> vec = board[x];
            unordered_set<char> seen;
            for (const char& letter : vec) {
                if (!seen.insert(letter).second  && (letter != '.')) {
                    return false;
                }
            }
        }

        //check each column
        for (int x = 0; x < 9; x++) {
            vector<char> vec;
            for (int y = 0; y < 9; y++) {
                vec.push_back(board.at(y).at(x));
            }
            unordered_set<char> seen;
            for (const char& letter : vec) {
                if (!seen.insert(letter).second  && (letter != '.')) {
                    return false;
                }
            }
        }

        //check each box
        for (int x = 0; x < 9; x++) {
            int xOffset, yOffset;
            switch(x) {
                case 0:
                    xOffset = 0;
                    yOffset = 0;
                    break;
                case 1:
                    xOffset = 3;
                    yOffset = 0;
                    break;
                case 2:
                    xOffset = 6;
                    yOffset = 0;
                    break;
                case 3:
                    xOffset = 0;
                    yOffset = 3;
                    break;
                case 4:
                    xOffset = 3;
                    yOffset = 3;
                    break;
                case 5:
                    xOffset = 6;
                    yOffset = 3;
                    break;
                case 6:
                    xOffset = 0;
                    yOffset = 6;
                    break;
                case 7:
                    xOffset = 3;
                    yOffset = 6;
                    break;
                case 8:
                    xOffset = 6;
                    yOffset = 6;
                    break;
            }
            vector<char> vec;
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {
                    vec.push_back(board.at(y+xOffset).at(z+yOffset));
                }
            }
            unordered_set<char> seen;
            for (const char& letter : vec) {
                if (!seen.insert(letter).second  && (letter != '.')) {
                    return false;
                }
            }
        }

        return true; */
    }
};
