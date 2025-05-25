#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    ll n; cin >> n;

    n = n * pow(10, 6) * 8;

    cout.precision(0);
    cout.setf(ios::fixed);
    
    cout << ceil(log(n)/log(2)) << endl;

    return 0;
}