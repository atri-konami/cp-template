/*
 * Range Sum Query(ver.SegTree)
 * author : atri^konami
 * update : add-single
 * query : range-add
 * test : 
 */

struct SegTree
{
    int N;
    vector<int> seg;

    SegTree(int n)
    {
        N = 1;
        while (N < n) N<<=1;
        seg.assign(2*N-1,0);
    }

    void add(int k,int x)
    {
        k += N-1;

        seg[k] += x;

        while(k>0)
        {
            k = (k-1)/2;
            seg[k] = seg[k*2+1] + seg[k*2+2];
        }
    }

    int sum(int a,int b) { return sum(a,b,0,0,N); }

    int sum(int a,int b,int k,int l,int r)
    {
        if ( r <= a || b <= l ) return 0;
        if ( a <= l && r <= b ) return seg[k];

        return sum(a,b,k*2+1,l,(l+r)/2) + sum(a,b,k*2+2,(l+r)/2,r);
    }
};
