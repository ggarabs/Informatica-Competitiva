#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+7, MAXN = 1e3+7;

int dp[MAXN][MAXN];

int main(){
        int n, k; cin >> n >> k;

        dp[0][0] = 1;

        for(int i = 1; i <= n+1; i++){
                for(int j = 0; j < k; j++){
                        dp[i][j+1] = dp[i-1][j] % INF;
                        dp[i][0] = (dp[i][0] + dp[i-1][j]) % INF;
                }
        }

        cout << dp[n+1][0] << endl;

        return 0;
}
