#include <bits/stdc++.h>

using namespace std;

int hamming_distance(string orig, string tent){
    int dist = 0;
    for(int i = 0; i < orig.size(); i++) dist += (orig[i] != tent[i]);
    return dist;
}         

int main(){
        string orig; cin >> orig;
        int k; cin >> k;

        int max_dist = orig.size();
        int ans = 0;

        for(int i = 1; i <= 5; i++){
                string tent; cin >> tent;
                int curr_dist = hamming_distance(orig, tent);
                if(curr_dist < max_dist){
                        max_dist = curr_dist;
                        ans = i;
                }
        }

        cout << ans << endl;
        cout << (max_dist > k ? -1 : max_dist) << endl;

        return 0;
}
