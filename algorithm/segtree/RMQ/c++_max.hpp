/*
 * RMaxQ-segtree
 * author : atri-konami
 * update : update-single
 * query : Max
 * test : 
 */
struct SegTree
{
    int N;
    vector<int> seg;

    SegTree(int n)
    {
        N = 1;
        while(N<n) N<<=1;
        seg.assign(2*N-1,INT_MIN);
    }

    void update(int k,int x)
    {
        k += N-1;

        seg[k] = x;

        while(k>0)
        {
            k = (k-1)/2;
            seg[k] = max(seg[k*2+1],seg[k*2+2]);
        }
    }

    int query(int a,int b) { return query(a,b,0,0,N); }

    int query(int a,int b,int k,int l,int r)
    {
        if ( r <= a || b <= l ) return INT_MIN;
        if ( a <= l && r <= b ) return seg[k];

        return max(query(a,b,k*2+1,l,(l+r)/2), query(a,b,k*2+2,(l+r)/2,r));
    }
};
