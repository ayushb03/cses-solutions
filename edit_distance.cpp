#include <iostream>
#include <string>
using namespace std;

// EDIT DISTANCE - https://cses.fi/problemset/task/1639/

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int ns1 = s1.size(), ns2 = s2.size();
    int dp[ns1 + 1][ns2 + 1];
    for(int i = 0; i <= ns1; ++i) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= ns2; ++j) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= ns1; ++i) {
        for(int j = 1; j <= ns2; ++j) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
            }
        }
    }
    cout << dp[ns1][ns2];
    return 0;
}
