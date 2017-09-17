class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        vector<int> rows(n, 0);
        vector<int> cols(n, 0);
        vector<int> recs(n, 0);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                auto ch = board[i][j];
                if (ch != '.') {
                    auto mask = 1 << (ch - '0');
                    if (rows[i] & mask || cols[j] & mask || recs[ i / 3 * 3 + j / 3] & mask)
                        return false;
                    rows[i] |= mask;
                    cols[j] |= mask;
                    recs[i / 3 * 3 + j  / 3] |= mask;
                }
            }
        }
        return true;
    }
};
