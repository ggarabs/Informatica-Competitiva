#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int MAXN = 2*1e5+7;

lli segTree[4*MAXN];

void build(int node, int l, int r, vector <lli> &values){
    if(l == r){
        segTree[node] = values[l-1];
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid, values);
    build(2*node+1, mid+1, r, values);

    segTree[node] = segTree[2*node] + segTree[2*node+1];
}

lli query(int node, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;

    if(ql <= l && r <= qr) return segTree[node];

    int mid = (l+r)/2;

    return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
}

void update(int node, int l, int r, int idx, int v){
    if(l == r){
        segTree[node] = v;
        return;
    }

    int mid = (l+r)/2;

    if(l <= idx && idx <= mid) update(2*node, l, mid, idx, v);
    else update(2*node+1, mid+1, r, idx, v);

    segTree[node] = segTree[2*node] + segTree[2*node+1];
}

int main(){
    int n, q; cin >> n >> q;

    vector <lli> values(n, 0);

    for(lli &x : values) cin >> x;

    build(1, 1, n, values);

    while(q--){
        int op; cin >> op;

        int a, b; cin >> a >> b;

        if(op == 1) update(1, 1, n, a, b);
        else cout << query(1, 1, n, a, b) << endl;
    }

    return 0;
}