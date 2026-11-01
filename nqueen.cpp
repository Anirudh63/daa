#include <iostream>
#include <vector>
using namespace std;

int n;

// Check whether position is safe
bool isSafe(vector<vector<int>>& board, int row, int col) {

    // Check same column
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check all four diagonals
    for (int d = 1; d < n; d++) {

        // Upper left
        if (row - d >= 0 && col - d >= 0 &&
            board[row - d][col - d] == 1)
            return false;

        // Upper right
        if (row - d >= 0 && col + d < n &&
            board[row - d][col + d] == 1)
            return false;

        // Lower left
        if (row + d < n && col - d >= 0 &&
            board[row + d][col - d] == 1)
            return false;

        // Lower right
        if (row + d < n && col + d < n &&
            board[row + d][col + d] == 1)
            return false;
    }

    return true;
}

// Solve N-Queens using backtracking
bool solve(vector<vector<int>>& board, int row,
           int fixedRow) {

    // All rows completed
    if (row == n)
        return true;

    // Skip row containing first queen
    if (row == fixedRow)
        return solve(board, row + 1, fixedRow);

    // Try every column
    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col)) {

            board[row][col] = 1;

            if (solve(board, row + 1, fixedRow))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    cout << "Enter N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid board size";
        return 0;
    }

    int r, c;

    cout << "Enter first queen position (row column): ";
    cin >> r >> c;

    // Convert 1-based to 0-based indexing
    r--;
    c--;

    if (r < 0 || r >= n || c < 0 || c >= n) {
        cout << "Invalid queen position";
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    // Place first queen
    board[r][c] = 1;

    if (solve(board, 0, r)) {

        cout << "\nSolution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

    } else {
        cout << "No solution exists";
    }

    return 0;
}
