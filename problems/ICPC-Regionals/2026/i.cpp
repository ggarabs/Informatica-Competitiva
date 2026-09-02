#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

vector<int> graph[MAXN];
vector<pair<int, long long int>> idx;
vector<pair<int, pair<int, int>>> acc;
map<int, int> coord;
bool vis[MAXN];

long long int DFS(int orig){
    vis[coord[orig]] = true;
    long long int acc = idx[coord[orig]].second;
    for(int i = 0; i < graph[coord[orig]].size(); i++){
        int viz = graph[coord[orig]][i];

        if(!vis[coord[viz]]){
            vis[coord[viz]] = true;
            acc += DFS(viz);
        }
    }

    return acc;
}

int main(){
    int f, n; cin >> f >> n;

    idx.push_back({0, 0});

    for(int i = 0; i < n; i++){
        int ki, pi; cin >> ki >> pi;
        coord[ki] = i+1;
        idx.push_back({ki, pi});
    }

    for(int i = 1; i <= n; i++){
        char op; cin >> op;

        if(op == 'A'){
            int ini, tmp; cin >> ini >> tmp;
            acc.push_back({idx[i].first, {ini, ini+tmp}});
        }else if(op == 'T'){
            int dep; cin >> dep;
            graph[coord[dep]].push_back(idx[i].first);
        }
    }

    vector<pair<long long int, long long int>> events;

    for(int i = 0; i < acc.size(); i++){
        int index = acc[i].first;
        int ini = acc[i].second.first;
        int fim = acc[i].second.second;

        if(!vis[coord[index]]) idx[coord[index]].second = DFS(index);

        events.push_back({ini, idx[coord[index]].second});
        events.push_back({fim, -idx[coord[index]].second});
    }

    sort(events.begin(), events.end());

    long long int curr = 0, ans = 0;
    for(int i = 0; i < events.size(); i++){
        curr += events[i].second;
        ans = max(ans, curr);
    }

    cout << (long long int)ans << endl;

    return 0;
}