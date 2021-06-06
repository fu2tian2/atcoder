// GCJ Moons and umbrellas
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

void solve(ll i) {
    ll x, y; cin >> x >> y;
    string s; cin >> s;
    ll n = s.length();
    vector<vector<ll>> dp(n,vector<ll>(2,INF));
    REP(i,n) {
        if (i==0) {
            if (s[i]=='C' || s[i]=='?') dp[i][0]=0;
            if (s[i]=='J' || s[i]=='?') dp[i][1]=0;
        }
        else {
            if (s[i]=='C' || s[i]=='?') {
                dp[i][0]=min(dp[i][0],dp[i-1][0]);
                dp[i][0]=min(dp[i][0],dp[i-1][1]+y);
            }
            if (s[i]=='J' || s[i]=='?') {
                dp[i][1]=min(dp[i][1],dp[i-1][1]);
                dp[i][1]=min(dp[i][1],dp[i-1][0]+x);
            }
        }
    }
    ll ans = min(dp[n-1][0],dp[n-1][1]);
    cout << "Case #" << i+1 << ": " << ans << endl;
    return;
}
int main(){
    ll t; cin >> t;
    REP(i,t) solve(i);
    return 0;
}