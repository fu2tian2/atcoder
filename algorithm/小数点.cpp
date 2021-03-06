//ABC189B 小数点誤差
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
int main(){
    ll n; ld x; cin >> n >> x; ld delta = 1e-12;
    ld bor = 0;
    REP(i,n) {
        ld v, p; cin >> v >> p;
        bor+=v*p/100;
        if (bor>x+delta) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}