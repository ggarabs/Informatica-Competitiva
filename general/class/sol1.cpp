#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n, q; cin >> n >> q;

    vector <int> values(n, 0);

    for(int &x : values) cin >> x;

    while(q--){
        int op; cin >> op;

        int a, b; cin >> a >> b;

        if(op == 1) values[a-1] = b;
        else{
            lli ans = 0;
            for(int i = a-1; i <= b-1; i++) ans += values[i];
            cout << ans << endl;
        }
    }

    return 0;
}