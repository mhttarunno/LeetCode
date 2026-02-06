class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    bool isSafe(int row, int col, int n) {
        int dubRow = row;
        int dubCol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }

        row = dubRow;
        col = dubCol;
        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }

        row = dubRow;
        col = dubCol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

    void printL(int col, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, n)) {
                board[row][col] = 'Q';
                printL(col + 1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        board.clear();
        for (int i = 0; i < n; ++i) {
            board.push_back(string(n, '.'));
        }
        printL(0, n);
        return ans;
    }
};
