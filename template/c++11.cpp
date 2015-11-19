#include <bits/stdc++.h>
using namespace std;

#define dump(x) (cerr << #x << "=" << x << endl)
#define all(x) (x).begin(),(x).end()
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define rep(i,n) REP(i,0,n)
#define erep(x,v) for(auto &x : (v))
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

template<class T> ostream& operator<<(ostream& os,const vector<T> v) {
    os << "[";
    for(int i=0; i<v.size(); i++){
        os << v[i] << ",";
    } 
    os << "]";
    return os;
}

template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2> p) {
        os << "(" << p.first << "," << p.second << ")"; return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> v;
    v.pb(1);v.pb(2);v.pb(4);v.pb(8);
    pair<int,int> p = make_pair(INT_MAX,INT_MIN);
    int x = 1;

    dump(x);
    cout << p << endl;
    cout << v << endl;
}
