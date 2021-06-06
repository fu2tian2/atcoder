// GCJ Reversort Engineering
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
    ll n, c; cin >> n >> c;
    vector<ll> ansl(n);
    REP(i,n) ansl[i]=i+1;
    vector<ll> cnter(n-1,0);
    if (c<n-1 || n*(n+1)/2<c+1) {
        cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
        return;
    }
    c-=(n-1);
    REP(i,n-1) {
        ll maxValue = n-i-1;
        cnter[i]=min(maxValue,c);
        c-=cnter[i];
    }
    // REP(i,n-1) cout << cnter[i] << " ";
    // cout << endl;
    FORD(i,n-2,0) {
        if (cnter[i]==0) continue;
        reverse(ansl.begin()+i,ansl.begin()+i+cnter[i]+1);
    }
    cout << "Case #" << i+1 << ": ";
    REP(i,n) cout << ansl[i] << " ";
    cout << endl;
    return;
}
int main(){
    ll t; cin >> t; 
    REP(i,t) solve(i);
    return 0;
}