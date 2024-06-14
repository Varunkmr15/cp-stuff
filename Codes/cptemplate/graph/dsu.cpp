//DSU O(4 Alpha) ~ O(1) avg
class DSU
{
public:
    vector<int> rank, par, size;

    DSU(int n = 0)
    {
        rank.resize(n + 1);
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findUpar(int node) //Find ultimate parent
    {
        if (node == par[node])
            return node;
        return par[node] = findUpar(par[node]); // path comp
    }

    void unionbyRank(int u, int v)
    {
        int UparU = findUpar(u);
        int UparV = findUpar(v);
        if (UparU == UparV)
            return;
        if (rank[UparU] < rank[UparV])
        {
            par[UparU] = UparV;
        }
        else
        {
            par[UparV] = UparU;
            rank[UparU] += (rank[UparU] == rank[UparV]);
        }
    }

    void unionbySize(int u, int v)
    {
        int UparU = findUpar(u);
        int UparV = findUpar(v);
        if (UparU == UparV)
            return;
        if (size[UparU] < size[UparV])
        {
            par[UparU] = UparV;
            size[UparV] += size[UparU];
        }
        else
        {
            par[UparV] = UparU;
            size[UparU] += size[UparV];
        }
    }
};
