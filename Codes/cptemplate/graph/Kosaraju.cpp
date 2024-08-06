// TC:O(V+E)
void topoSort(int start, vector<int> *edges, vector<int>& topo, vector<bool>& visited) {
	visited[start] = true;
	for (auto i : edges[start]) {
		if (!visited[i]) {
			topoSort(i, edges, topo, visited);
		}
	}
	topo.pb(start);
}
void getComponent(int start, vector<int>* edges, vector<int>& currComponent, vector<bool>& visited) {
	currComponent.pb(start);
	visited[start] = true;
	for (auto i : edges[start]) {
		if (!visited[i]) {
			getComponent(i, edges, currComponent, visited);
		}
	}
}
vector<vector<int>> getSCC(int n, vector<int>* edges, vector<int>* edgesT) {
	vector<bool> visited(n);
	vector<int> topo;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			topoSort(i, edges, topo, visited);
		}
	}
	fill(visited.begin(), visited.end(), false);
	vector<vector<int>> SCC;
	for (int i = topo.size() - 1; i >= 0; i--) {
		if (!visited[topo[i]]) {
			vector<int> comp;
			getComponent(topo[i], edgesT, comp, visited);
			SCC.pb(comp);
		}
	}
	return SCC;
}
void solve() {
	int n, e;
	cin >> n >> e;
	vector<int> *edges = new vector<int>[n];
	vector<int> *edgesT = new vector<int>[n];
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].pb(b - 1);
		edgesT[b - 1].pb(a - 1);
	}
	vector<vector<int>> SCC = getSCC(n, edges, edgesT);
}
