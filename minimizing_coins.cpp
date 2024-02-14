#include<bits/stdc++.h>
using namespace std;

// MINIMIZING COINS - https://cses.fi/problemset/task/1634/

int main() {
    int n, x;
    cin >> n >> x;
    int c[n], dp[x + 1];
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for(int i = 0; i <= x; ++i) {
        dp[i] =  1e9;
    }
    dp[0] = 0;
    for(int i = 1; i <= x; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >= c[j]) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    if(dp[x] == 1e9) {
        cout << -1;
    }
    else {
        cout << dp[x]   ;
    }
    return 0;
}