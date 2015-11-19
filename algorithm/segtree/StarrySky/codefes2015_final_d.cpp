#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int N;
    vector<int> dat,sum;

    SegTree(int n)
    {
        N = 1;
        while(N<n) N<<=1;
        dat.assign(2*N-1,0);
        sum.assign(2*N-1,0);
    }

    void add(int a,int b,int x) { add(a,b,x,0,0,N); }

    int add(int a,int b,int x,int k,int l,int r)
    {
        if ( r <= a || b <= l ) return dat[k];
        if ( a <= l && r <= b )
        {
            sum[k] += x;
            return dat[k] += x;
        }

        return dat[k] = max(add(a,b,x,k*2+1,l,(l+r)/2),add(a,b,x,k*2+2,(l+r)/2,r)) + sum[k];
    }

    int maximum(int a,int b) { return maximum(a,b,0,0,N); }

    int maximum(int a,int b,int k,int l,int r) 
    {
        if ( r <= a || b <= l ) return INT_MIN;
        if ( a <= l && r <= b ) return dat[k];

        return max(maximum(a,b,k*2+1,l,(l+r)/2), maximum(a,b,k*2+2,(l+r)/2,r)) + sum[k];
    }
};

int main()
{
    int N;
    SegTree seg(100000);
    vector<pair<int,int>> v;

    cin >> N;

    for(int i=0; i<N; i++){
        int s,t;
        cin >> s >> t;
        seg.add(s-1,t-1,1);
        v.emplace_back(s-1,t-1);
    }

    int res = INT_MAX;

    for(int i=0; i<N; i++){
        pair<int,int> p = v[i];

        seg.add(p.first,p.second,-1);
        res = min(res,seg.maximum(0,100000));
        seg.add(p.first,p.second,1);
    }

    cout << res << endl;
}
