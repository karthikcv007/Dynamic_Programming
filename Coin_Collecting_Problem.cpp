#include <iostream>
using namespace std;

int maxCoins(int grid[][100], int m, int n) {
    int dp[m][n];

    // Initialize the top-left cell
    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the dp array
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // The bottom-right cell contains the maximum coins collected
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int grid[100][100];
    cout << "Enter the coin values in each cell of the grid:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int maxCollected = maxCoins(grid, m, n);
    cout << "The maximum number of coins collected is: " << maxCollected << endl;

    return 0;
}
