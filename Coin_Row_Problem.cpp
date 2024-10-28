#include <iostream>
using namespace std;

int maxCoinSum(int coins[], int n) {
    if (n == 0) return 0;
    if (n == 1) return coins[0];

    int prev2 = coins[0];
    int prev1 = max(coins[0], coins[1]);
    int current;

    for (int i = 2; i < n; ++i) {
        current = max(prev1, coins[i] + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    int coins[n];
    cout << "Enter the values of the coins: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int maxSum = maxCoinSum(coins, n);
    cout << "The maximum sum of non-adjacent coins is: " << maxSum << endl;

    return 0;
}
