#include<bits/stdc++.h>
using namespace std;

// COIN COMBINATIONS 1 - https://cses.fi/problemset/task/1635

int main() {
    const int MOD = 1e9 + 7;
    int n, x;
    cin >> n >> x;
    int c[n], dp[x + 1];
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for(int i = 0; i <= x; ++i) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i <= x; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >= c[j]) {
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }
    cout << dp[x];
    return 0;
}