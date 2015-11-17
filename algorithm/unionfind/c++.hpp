struct UnionFind{
    UnionFind(int n){
        par.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            par[i]=i;
            rank[i]=0;
        }
    }

    void unite(int x,int y)
    {
        x = root(x);y = root(y);
        if(x == y) return;

        if( rank[x] < rank[y] )
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if(rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }

    bool same(int x,int y)
    {
        return root(x) == root(y);
    }

private:
    vector<int> par,rank;

    int root(int x)
    {
        if (x == par[x]) return x;

        return par[x] = root(par[x]);
    }
};
