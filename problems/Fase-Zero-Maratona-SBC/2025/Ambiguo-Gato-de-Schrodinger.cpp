#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int c, g; cin >> c >> g;

    if(c == 1){
        cout << "vivo e morto" << endl;
    }else{
        if(g == 1) cout << "vivo" << endl;
        else cout << "morto" << endl;
    }
    exit(0);
}