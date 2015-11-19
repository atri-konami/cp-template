#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int N;
    vector<int> seg;

    SegTree(int n)
    {
        N = 1;
        while (N < n) N<<=1;
        seg.assign((N<<1)-1,0);
    }

    void add(int k,int x)
    {
        k += N-1;

        seg[k] += x;

        while(k>0)
        {
            k = (k-1)>>1;
            seg[k] = seg[(k<<1)+1] + seg[(k<<1)+2];
        }
    }

    int sum(int a,int b) { return sum(a,b,0,0,N); }

    int sum(int a,int b,int k,int l,int r)
    {
        if ( r <= a || b <= l ) return 0;
        if ( a <= l && r <= b ) return seg[k];

        return sum(a,b,(k<<1)+1,l,(l+r)>>1) + sum(a,b,(k<<1)+2,(l+r)>>1,r);
    }
};

int main()
{
    int N,Q;
    cin >> N >> Q;

    SegTree seg(N);

    for(int i=0; i<Q; i++)
    {
        int c,x,y;
        cin >> c >> x >> y;

        if(c)
        {
            cout << seg.sum(x-1,y) << endl;
        }
        else
        {
            seg.add(x-1,y);
        }
    }
}
