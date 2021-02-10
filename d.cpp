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
#define N 110000000
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
int main(){
  ll n; cin >> n;
  ll ans = 0;
  FOR(i,1,N) {
    ll x = (i+i*i)/2;
    if (n>=x && (n-x)%i==0){
      ans += 2;
    }
  }
  cout << ans << endl;
  return 0;
}