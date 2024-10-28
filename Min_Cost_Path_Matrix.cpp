#include <iostream>
using namespace std;

int minCostPath(int cost[][100], int m, int n) {
    int dp[m][n];
    
    // Initialize the top-left cell
    dp[0][0] = cost[0][0];

    // Fill the first row
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    }

    // Fill the first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }

    // Fill the rest of the dp array
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + cost[i][j];
        }
    }

    // The bottom-right cell contains the minimum cost path
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int cost[100][100];
    cout << "Enter the cost values in each cell of the matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    int minCost = minCostPath(cost, m, n);
    cout << "The minimum cost to reach the bottom-right cell is: " << minCost << endl;

    return 0;
}
