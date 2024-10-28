#include <iostream>
using namespace std;

int longestCommonSubsequence(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    int dp[m + 1][n + 1];

    // Initialize the dp array
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // Base case: LCS of any string with an empty string is 0
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The bottom-right cell contains the length of LCS
    return dp[m][n];
}

int main() {
    string X, Y;

    cout << "Enter the first string: ";
    cin >> X;

    cout << "Enter the second string: ";
    cin >> Y;

    int lcsLength = longestCommonSubsequence(X, Y);
    cout << "The length of the longest common subsequence is: " << lcsLength << endl;

    return 0;
}
