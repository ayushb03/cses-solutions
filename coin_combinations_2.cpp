#include <iostream>
#include <cmath>
using namespace std;

// COIN COMBINATIONS 2 - https://cses.fi/problemset/task/1636

int main() {
    const int MOD = 1000000007;
    int n, x;
    cin >> n >> x;
    int c[n], dp[n + 1][x + 1];
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= x; ++j) {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for(int i = n - 1; i >= 0; --i) {
        for(int k = 0; k <= x; ++k) {
            if(k >= c[i]) {
                dp[i][k] = (dp[i][k - c[i]] + dp[i + 1][k]) % MOD;
            }
            else {
                dp[i][k] = dp[i + 1][k] % MOD;
            }
        }
    }
    cout << dp[0][x];
    return 0;
}

