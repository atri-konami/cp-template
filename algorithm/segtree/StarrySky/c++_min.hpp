/*
 * Starry Sky(ver.min)
 * update : add-range
 * query : range-min
 * author : atri_konami
 * test: none
 */

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

        return dat[k] = min(add(a,b,x,k*2+1,l,(l+r)/2),add(a,b,x,k*2+2,(l+r)/2,r)) + sum[k];
    }

    int minimum(int a,int b) { return minimum(a,b,0,0,N); }

    int minimum(int a,int b,int k,int l,int r) 
    {
        if ( r <= a || b <= l ) return INT_MAX;
        if ( a <= l && r <= b ) return dat[k];

        return min(minimum(a,b,k*2+1,l,(l+r)/2), minimum(a,b,k*2+2,(l+r)/2,r)) + sum[k];
    }
};
