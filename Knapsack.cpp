#include <iostream>
using namespace std;

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    // Build the dp table
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: 0 items or 0 capacity
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right cell contains the maximum value for the given capacity
    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], values[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    int maxVal = knapsack(W, weights, values, n);
    cout << "The maximum value that can be obtained is: " << maxVal << endl;

    return 0;
}
