#include <bits/stdc++.h>
#define MAXP 37

using namespace std;

int main(){
        int t;
        while(cin >> t && t){
                vector <pair<int, int>> prod(t+1, {0, 0});
                for(int i = 1; i <= t; i++) cin >> prod[i].first >> prod[i].second;

                vector <vector <int>> dp(t+1, vector<int>(MAXP, 0));

                int w; cin >> w;

                for(int i = 1; i <= t; i++){
                        for(int j = 1; j <= w; j++){
                                if(prod[i].second > j) dp[i][j] = dp[i-1][j];
                                else dp[i][j] = max(dp[i-1][j], prod[i].first + dp[i-1][j-prod[i].second]);
                        }
                }

                cout << dp[t][w] << endl;
        }
        return 0;
}
