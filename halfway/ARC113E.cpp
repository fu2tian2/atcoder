#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define vec2(name,i,j,k) vector<vector<ll>> name(i,vector<ll>(j,k))
#define vec3(name,i,j,k,l) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k,l)))
#define pb push_back
#define MOD 1000000007 //998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

void solve() {
    string s; cin >> s;
    ll len = s.length();
    ll acnt = 0; ll bcnt = 0;ll lasta = -1; ll lastb = -1;
    ll adiv = 0;
    ll bdiv = 0;
    REP(i,s.length()) {
        if (s[i]=='a') {
            acnt++;
            if (lasta!=-1 && lasta!=i-1) adiv++;
            lasta = i;
        }
        else {
            bcnt++;
            if (lastb!=-1 && lastb!=i-1) bdiv++;
            lastb = i;
        }
    }
    string ans = "";
    cout << adiv << " " << bdiv << endl;
    if (adiv==0 && bdiv==0){
        cout << s << endl;
        return;
    }
    if (acnt%2==0) {
        REP(i,bcnt) ans = ans+'b';
        REP(i,acnt-2*((bdiv+1)/2)) ans = ans+'a';
        cout << ans << endl;
        return;
    }
    if (s[len-3]=='a' && s[len-2]=='b' && s[len-1]=='b') {
        bcnt-=2;
        REP(i,bcnt) ans = ans + 'b';
        ans = ans + "abb";
        cout << ans << endl;
        return;
    }
    if (s[len-2]=='a' && s[len-1]=='b') {
        bcnt-=1;
        REP(i,bcnt) ans = ans + 'b';
        ans = ans + "ab";
        cout << ans << endl;
        return;
    }
    if (s[len-3]=='b' && s[len-2]=='b' && s[len-1]=='b') {
        bcnt-=2;
        cout << "check" << endl;
        REP(i,bcnt) ans = ans+'b';
        REP(i,acnt-2*((bdiv+1)/2)) ans = ans+'a';
        cout << ans << endl;
        return;
    }
    REP(i,bcnt) ans = ans+'b';
    REP(i,acnt-2*((bdiv+1)/2)) ans = ans+'a';
    cout << ans << endl;
    return;
}

int main(){
    ll t; cin >> t;
    REP(i,t) solve();
    return 0;
}