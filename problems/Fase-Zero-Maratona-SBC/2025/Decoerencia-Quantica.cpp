#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;

    string w1, w2; cin >> w1 >> w2;

    double v1 = 0, v2 = 0;
    for(char aux : w1){
        v1 += (aux == '*');
    }

    for(char aux : w2){
        v2 += (aux == '*');
    }

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << 1-(v2/v1) << endl;

    exit(0);
}