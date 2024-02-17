#include <bits/stdc++.h>
using namespace std;

// REMOVAL GAME - https://cses.fi/problemset/task/1097

int main() {
    int n;
    cin >> n;
    int x[n];
    long long sum = 0;
    for (int &e : x) {
        cin >> e;
        sum += e;
    }

    long long dp[n][n];
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                dp[l][r] = x[l];
            }
            else {
                dp[l][r] = max(x[l] - dp[l + 1][r],
                               x[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << endl;
}