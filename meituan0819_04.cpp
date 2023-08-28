#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    int a[105];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            for (int k = 1; k <= j; k++) {
                if (k != a[i]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
                }
            }
        }
    }
    cout << dp[n][sum] << endl;
    return 0;
}
