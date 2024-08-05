// O(n ^ 3)
// All pair shortest paths
// Negative Cycle needs to be checked otherwise the answer can be very negative resulting in overflows
vector<int> constructPath(int u, int v) { 
    if (Next[u][v] == -1) 
        return {}; 
    vector<int> path = { u }; 
    while (u != v) { 
        u = Next[u][v]; 
        path.push_back(u); 
    } 
    return path; 
} 

void FloydWarshall(int n, vector<pair<int, ll>> *adj, vector<vector<ll>> &dist) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (auto j : adj[i]) {
			dist[i][j.ff] = min(dist[i][j.ff], j.ss);
		}
	}
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) 
                Next[i][j] = -1; 
            else
                Next[i][j] = j; 
        } 
    } 
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				if (dist[i][j] > dis[i][k] + dis[k][j]) { 
                    dis[i][j] = dis[i][k] + dis[k][j]; 
                    Next[i][j] = Next[i][k]; 
                } 
			}
		}
	}
}
