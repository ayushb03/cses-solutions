#include<bits/stdc++.h>
using namespace std;

// REMOVING DIGITS - https://cses.fi/problemset/task/1637/

int main() {
    int n;
    cin >> n;
    int dp[n + 1];
    for (int i = 0; i <= 9; ++i) {
        dp[i] = 1;
    }
    for(int i = 10; i <= n; ++i) {
        dp[i] = 1e6 + 1;
    }
    for(int i = 10; i <= n; ++i) {
        int x = i;
        while(x != 0) {
            int d = x % 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
            x /= 10;
        }
    }
    cout << dp[n];
    return 0;
}
