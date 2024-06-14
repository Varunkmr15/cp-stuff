/*
dfs function to calculate distance to
a node
*/

void dfs(int x, int p, vector<int> &depth, vector<vector<int>> &graph)
{
    for (auto e : graph[x])
    {
        if (e != p)
        {
            depth[e] = depth[x] + 1;
            dfs(e, x, depth, graph);
        }
    }
}

/*
dfs2 function to calculate the path
from x (having parent p) -> v
return path from v -> x and
return empty vector if doesn't exist
*/

vector<int> dfs2(int x, int p, int v, vector<vector<int>> &graph)
{
    if (x == v)
    {
        return {x};
    }
    for (auto e : graph[x])
    {
        if (e != p)
        {
            vector<int> out = dfs2(e, x, v, graph);
            if (sz(out))
            {
                out.pb(x);
                return out;
            }
        }
    }
    return {};
}