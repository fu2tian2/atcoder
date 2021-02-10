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
#define N 210000
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
vector<ll> a(N);
vector<ll> b(N);
vector<ll> p(N);

int main() {
  ll n; cin >> n;

}

// int main() {
//   ll n; cin >> n;
//   map<ll,ll> m;
//   REP(i,2*n) {
//     m[i]=i;
//   }
//   REP(i,n) {
//     // m.erase(i*2);
//     m[i]=0;
//   }
//   cout << "test1" << endl;
//   for (auto iter=m.begin();iter!=m.end();iter++) {
//     cout << iter->first << " " << iter->second << endl;
//   }
// }

// int main(){
//   map<ll,ll> a;
//   ll n; cin >> n;
//   REP(i,n) {
//     a[2*i]=1;
//   }
//   ll cnt = 0;
//   for (auto ite=a.begin();ite!=a.end();ite++) {
//     cnt++;
//     cout << cnt << endl;
//   }
//   cout << cnt << endl;
// }

// int main() {
//   vector<ll> a = {2,3};
//   ll n; cin >> n;
//   // REP(i,n) {
//   //   ll ind = lower_bound(a.begin(),a.end(),i)-a.begin();
//   //   cout << i << " " << ind << endl;
//   // }
//   for (auto ite=a.begin();ite!=a.end();ite++) {
//     cout << *ite << endl;
//   }
// }