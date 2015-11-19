#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int N;
    vector<int> seg;

    SegTree(int n)
    {
        N = 1;
        while(N<n) N<<=1;
        seg.assign(2*N-1,INT_MAX);
    }

    void update(int k,int x)
    {
        k += N-1;

        seg[k] = x;

        while(k>0)
        {
            k = (k-1)/2;
            seg[k] = min(seg[k*2+1],seg[k*2+2]);
        }
    }

    int query(int a,int b) { return query(a,b,0,0,N); }

    int query(int a,int b,int k,int l,int r)
    {
        if ( r <= a || b <= l ) return INT_MAX;
        if ( a <= l && r <= b ) return seg[k];

        return min(query(a,b,k*2+1,l,(l+r)/2), query(a,b,k*2+2,(l+r)/2,r));
    }
};

int main()
{
    int N,Q;

    cin >> N >> Q;

    SegTree seg(N);

    for(int i=0;i<Q;i++)
    {
        int c,x,y;
        cin >> c >> x >> y;

        if(c)
        {
            cout << seg.query(x,y+1) << endl;
        }
        else
        {
            seg.update(x,y);
        }
    }
}
