// n->number of node, m-> number of edges
vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int>dist(n,INT_MAX/2);
        vector<int>adj[n];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                int dis=dist[node]+1;
                if(dis<dist[x]){
                    dist[x]=dis;
                    q.push(x);
                }
            }
        }
        for(auto &x:dist){
            if(x==INT_MAX/2){
                x=-1;
            }
        }
        return dist;
    }
