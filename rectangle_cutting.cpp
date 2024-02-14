#include<bits/stdc++.h>
using namespace std;

// RECTANGLE CUTTING - https://cses.fi/problemset/task/1744

int main() {
    int a, b;
    cin >> a >> b;
    int dp[a + 1][b + 1];
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            dp[i][j] = i == j ? 0 : 1e9;
        }
    }
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            for(int v = 1; v < i; ++v) {
                dp[i][j] = min(dp[i][j], 1 + dp[v][j] + dp[i - v][j]);
            }
            for(int h = 1; h < j; ++h) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][h] + dp[i][j - h]);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}
