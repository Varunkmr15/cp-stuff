    void toposort(int i,vector<vector<int>>adj[],vector<int>&vis,stack<int>&st){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x[0]]){
                toposort(x[0],adj,vis,st);
            }
        }
        st.push(i);
    }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<int>dist(n,1e9);
        vector<vector<int>>adj[n];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        stack<int>st;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                toposort(i,adj,vis,st);
            }
        }
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto x:adj[node]){
                int dis=dist[node]+x[1];
                if(dis<dist[x[0]]){
                    dist[x[0]]=dis;
                }
            }
        }
        for(auto &x:dist){
            if(x==1e9){
                x=-1;
            }
        }
        return dist;
    }
