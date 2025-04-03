class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                string num = string(1, board[i][j]);
                string rowCheck = num + " in row " + to_string(i);
                string colCheck = num + " in col " + to_string(j);
                string boxCheck = num + " in box " + to_string(i / 3) + to_string(j / 3);
                if (seen.count(rowCheck) || seen.count(colCheck) || seen.count(boxCheck)) {
                    return false;
                }
                seen.insert(rowCheck);
                seen.insert(colCheck);
                seen.insert(boxCheck);
            }
        }
        return true;
    }
};