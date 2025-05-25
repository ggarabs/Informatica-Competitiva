#include <bits/stdc++.h>
#define lli long long int

using namespace std;

string value;
lli convert(string x){
    lli ans = 0;
    for(int l = 0; l < x.size(); l++) ans += ((x[l]-'0')*1LL << x.size()-1-l);
    return ans;
}

int main(){
    lli x; cin >> x;

    while(x > 0){
        value.push_back((x%2)+'0');
        x /= 2;
    }
    reverse(value.begin(), value.end());

    bool pal = true;
    for(int l = 0; l < value.size()/2; l++){
        if(value[l] != value[value.size()-1-l]){
            pal = false;
            break;
        }
    }
    if(pal){
        cout << (lli)convert(value) << endl;
        return 0;
    }
    
    int tam = value.size(), l = (tam % 2) ? tam/2 : tam/2-1, r = tam/2;
    string ans1 = value, ans2 = value;

    while(l >= 0 && r <= tam-1 && !(ans1[l] == '1' || ans1[r] == '1')) l--, r++;

    int copy_l = l, copy_r = r;

    if(ans1[r] == '1') ans1[r] = '0';
    if(ans1[l] == '1'){
        ans1[l] = '0';
        l++, r--;
        while(l <= r) ans1[r--] = ans1[l++] = '1';
    }

    while(copy_l >= 0 && copy_r <= tam-1) ans1[copy_r++] = ans1[copy_l--];
    if(ans1[0] == '0') ans1[tam-1] = '1';

    l = (tam % 2) ? tam/2 : tam/2-1, r = tam/2;

    while(l >= 0 && r <= tam-1 && ans2[l] == ans2[r]) l--, r++;

    copy_l = l, copy_r = r;

    if(ans2[r] == '1') ans2[r] = '0';
    else if(ans2[l] == '1'){
        ans2[l] = '0';
        l++, r--;
        while(l <= r) ans2[r--] = ans2[l++] = '1';
    }

    while(copy_l >= 0 && copy_r <= tam-1) ans2[copy_r++] = ans2[copy_l--];
    if(ans2[0] == '0') ans2[tam-1] = '1';

    cout << (lli)max(convert(ans1), convert(ans2)) << endl;

    return 0;
}