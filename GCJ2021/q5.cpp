// GCJ Cheating Detection
// 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007 //998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

void solve(ll x) {
    vector<string> q(100);
    vector<ld> diff(10000);
    vector<ld> maxSolved(100,-INF);
    vector<ld> minCant(100,INF);
    REP(i,100) cin >> q[i];
    REP(i,10000) {
        ll cnt = 0;
        REP(j,100) if (q[j][i]=='1') cnt++;
        ld p = (ld)cnt/(ld)100;
        diff[i] = log(((ld)1/p)-1);
    }
    REP(i,100) REP(j,10000) {
        if (q[i][j]=='1') maxSolved[i]=max(maxSolved[i],diff[j]);
        else minCant[i]=min(minCant[i],diff[j]);
    }
    ld maxNg = 0;
    ll ans;
    REP(i,100) {
        ld ng = maxSolved[i]-minCant[i];
        if (ng<=0) continue;
        else if (maxNg<ng) {
            maxNg = max(maxNg,ng);
            ans = i+1;
        }
    }
    
    // ll maxNg = 0;
    // ll ans;
    // REP(i,100) {
    //     ll cnt=  0;
    //     REP(j,10000) {
    //         if (minCant[i]<=diff[j] && diff[j]<=maxSolved[i]) cnt++;
    //     }
    //     if (maxNg<=cnt){
    //         ans = i;
    //         maxNg = cnt;
    //     }
    //     cout << i << " " << cnt << endl;
    // }
    // ll a = 0; ll b = 0; ll c = 0; ll d = 0; ll e = 0;
    // REP(i,10000) {
    //     if (diff[i]<-2) a++;
    //     else if (diff[i]<-1) b++;
    //     else if (diff[i]<0) c++;
    //     else if (diff[i]<1) d++;
    //     else e++;
    // }
    // cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    // REP(i,100) cout << i << " " << diff[i] << endl;
    // REP(i,100) cout << i << " " << maxSolved[i] << " " << minCant[i] << endl;
    cout << "Case #" << x+1 << ": " << ans << endl;
}
int main(){
    ll t, p; cin >> t >> p;
    REP(i,t) solve(i);
    return 0;
}