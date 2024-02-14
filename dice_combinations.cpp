#include <iostream>
#include <cmath>
using namespace std;

// DICE COMBINATIONS - https://cses.fi/problemset/task/1633

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int dp[n + 1];
    // Initialize dp array
    for(int i = 0; i <= n; ++i) {
        dp[i] = 0; // Initialize all values to 0
    }
    dp[0] = 1; // Base case

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= 6; ++j) { // Fix: Corrected the loop condition
            if(i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
