#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    ll y, k; cin >> y >> k;

    vector <int> d;
    ll maior = 0;

    for(int i = 1; i*i <= y; i++){
        if(y % i) continue;

        if(y/i == i) d.push_back(i);
        else{
            d.push_back(i);
            d.push_back(y/i);
        }
    }

    sort(d.begin(), d.end());

    int cur = 1;
    ll ans = 1;
    for(int i = 1; i < d.size(); i++){
        if(k <= 0) break;
        if(d[i] % cur == 0){
            if(k < ((d[i]-cur)/cur)) ans += k*cur;
            else{
                k -= (d[i]-cur)/cur;
                ans += d[i]-cur;
                cur = d[i];
            }
        }
    }

    if(k > 0) ans += k*cur;
    cout << ans << endl;

    return 0;

}