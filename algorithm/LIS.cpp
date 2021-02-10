//ABC165F
//https://qiita.com/python_walker/items/d1e2be789f6e7a0851e5
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 1000000000000000
#define N 210000

vector<ll> a(N,INF);
vector<ll> ansl(N);
vector<ll> bango(N);
vector<ll> reached(N,0);
vector<vector<ll>> conn(N);


//探索するものを定義しておく,初期値設定の値に注意!!
//大きい順に並んでいて、自分より小さいものの最小のindexを見つける
//自分より大きいもの見つけたければ昇順のvectorに対して不等号逆にする
bool isOK(ll index, ll key){ 
    if (a.at(index) >= key) return true; 
    else return false;
}

ll binse(ll key, ll sizem){ //sizem番目まで二分探索
	ll left = -1;
	ll right = sizem;
	while (right-left>1){
		ll mid = left+(right-left)/2;
		if (isOK(mid, key)) right = mid;
		else left = mid;
	}
	return right; //自分より大きい、または小さいものの最小のindex、なければsizemを返す
}

void dfs(ll x){
	reached[x] = 1;
	ll len = conn[x].size();
	ll ind = binse(bango[x],N-1); // a内で二分探索
	ll former = a[ind]; // 別の枝に移った時に戻せるようにもとの値を記録しておく.
	a[ind] = bango[x];
	ansl[x] = binse(INF/10,N-1); //INFじゃないところの長さがLIS.
	// cout << x << " " << ansl[x] << " " << ind << endl;
	if (len!=0){
		REP(i,len){
			if (reached[conn[x][i]]==0){
				dfs(conn[x][i]);
			}
		}
	}
	a[ind] = former; // もとの値に戻す.
}

int main(){
	ll n, x, u, v; cin >> n;
	REP(i,n){
		cin >> x;
		bango[i] = x;
	}
	REP(i,n-1){
		cin >> u >> v;
		conn[u-1].pb(v-1);
		conn[v-1].pb(u-1);
	}
	dfs(0);
	REP(i,n){
		cout << ansl[i] << endl;
	}
}