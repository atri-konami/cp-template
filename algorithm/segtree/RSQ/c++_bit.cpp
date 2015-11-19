/*
 * Binary-Indexed Tree (1-origin)
 * author : atri-konami
 * update : add-single
 * query : range-sum
 * test : AOJ DSL_2 Problem B - Range Sum Query
 */

struct BIT
{
    int N;
    vector<int> bit;

    BIT(int n):N(n)
    {
        bit.assign(N+1,0);
    }

    void add(int k,int x)
    {
        for(int i=k; i<=N; i+=i&-i)
        {
            bit[i] += x;
        }
    }

    int sum(int k)
    {
        int ret = 0;

        for(int i=k; i>0; i-=i&-i)
        {
            ret += bit[i];
        }

        return ret;
    }
};
