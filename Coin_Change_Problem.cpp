#include <iostream>
using namespace std;

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];

    // Initialize dp array; dp[i] will hold the minimum coins for amount i.
    for (int i = 0; i <= amount; ++i) {
        dp[i] = amount + 1;  // Set to an amount larger than any possible solution
    }
    dp[0] = 0; // Base case: 0 coins are needed to make 0 amount.

    // Populate dp array
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // If we didn't find a solution, dp[amount] will be greater than amount
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int n, amount;

    cout << "Enter the number of coin denominations: ";
    cin >> n;

    int coins[n];
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << "Enter the amount to make: ";
    cin >> amount;

    int result = minCoins(coins, n, amount);
    if (result == -1) {
        cout << "It's not possible to make the given amount with the available coins." << endl;
    } else {
        cout << "The minimum number of coins required: " << result << endl;
    }

    return 0;
}
