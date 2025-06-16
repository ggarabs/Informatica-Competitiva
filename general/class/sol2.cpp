#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n, q; cin >> n >> q;

    vector <lli> values(n, 0);

    for(lli &x : values) cin >> x;

    vector <lli> prefix_sum(n+1, 0);

    for(int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i-1] + values[i-1];

    while(q--){
        int op; cin >> op;

        int a, b; cin >> a >> b;

        if(op == 1){
            values[a-1] = b;
            for(int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i-1] + values[i-1];
        }else{
            cout << prefix_sum[b]-prefix_sum[a-1] << endl;
        }
    }

    return 0;
}
