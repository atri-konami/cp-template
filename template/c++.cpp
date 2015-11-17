#include <bits/stdc++.h>
using namespace std;

#define dump(x) (cerr << #x << "=" << x << endl)

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define repp(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define _foreach(x,v) for(auto &x : (v))
#define pb push_back

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
    vector<int> v;
    v.pb(1);v.pb(2);v.pb(4);v.pb(8);
    pair<int,int> p = make_pair(INT_MAX,INT_MIN);
    int x = 1;

    dump(x);
    cout << p << endl;
    cout << v << endl;
}
