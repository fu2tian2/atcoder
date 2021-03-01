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
    //変数宣言（空集合）
  // set<int> s;
  // cout << s.empty() << endl;//1:TRUE

  // //変数宣言と同時に初期化
  // set<int> ss{3,1,4,5};
  // cout << ss.size() << endl;//4

  //要素を追加
  // s.insert(3);s.insert(1);s.insert(5);
  // cout << s.size() << endl;//3
  // s.insert(1);
  // cout << s.size() << endl;//3（要素は重複しない）

  //各要素へのアクセス
  // for(auto i=s.begin();i!=s.end();i++)cout << *i << endl;//1 3 5

  // //各要素へのアクセス（逆順）
  // for(auto i=s.rbegin();i!=s.rend();i++)cout << *i << endl;//5 3 1

  // //要素の削除
  // s.erase(3);
  // cout << s.size() << endl;//2
  // s.erase(100);//元から無い要素をeraseしても変化はない（エラーも吐かない）
  // cout << s.size() << endl;//2

  // s.insert(3);

  // //要素の検索
  // auto itr = s.find(3);
  // cout << *itr << endl;//3
  // //要素が見つからない場合はitr == s.end()
  // itr = s.find(99);
  // int a;
  // a = itr == s.end() ? 1 : 0;
  // cout << a << endl;//1

  // //2分探索
  // itr = s.lower_bound(3);
  // cout << *itr << endl; //3
  // itr = s.upper_bound(3);
  // cout << *itr << endl; //5

  // //集合の要素をすべて削除
  // s.clear();

  set<ll> s;
  s.insert(1);
  s.insert(3);
  s.insert(5);
  auto x = s.lower_bound(4);
  cout << "test1 " << *x << endl;
  x--;
  cout << "test1.5 " << *x << endl;
  cout << "test2 " << *x-- << endl;
  cout << "test3 " << *x << endl;
  auto y = s.upper_bound(4);
  cout << "test4 " << *y << endl;
  y++;
  cout << "test5 " << *y << endl; //overしてる

  multiset<ll> t;
  t.insert(1);
  t.insert(3);
  t.insert(5);
  t.insert(5);
  t.insert(7);
  auto ite = t.lower_bound(5);
  cout << "test6 " << *ite << endl;
  ite++;
  
  cout << "test7 " << *ite << endl;
  t.erase(5);
  auto ite2 = t.lower_bound(5);
  cout << "test8 " << *ite2 << endl;
  t.insert(6);
  t.insert(8);
  cout << "test8.5 " << *ite2 << endl;
  t.erase(ite2);

  cout << "test9 " << t.size() << endl;
  // cout << "test10 " << *ite2 << endl;
  // ite2++;
  // cout << "test11 " << *ite2 << endl;
  // ite2--;
  // cout << "test12 " << *ite2 << endl;
}