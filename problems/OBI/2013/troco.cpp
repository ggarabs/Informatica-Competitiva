#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e5+7;

bool dp[MAXV];

int main(){
        int v, m; cin >> v >> m;

        vector <int> moedas(m, 0);
        for(int &x: moedas) cin >> x;

        dp[0] = 1;

        for(int i = 0; i < m; i++){
                for(int j = v; j >= 0; j--){
                        if(dp[j] && j+moedas[i] <= v) dp[j+moedas[i]] = 1;
                }
        }

        cout << (dp[v] ? 'S' : 'N') << endl;

        return 0;
}
