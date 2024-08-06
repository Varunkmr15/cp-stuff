// O(NlogN)
// could use priority queue also but set is a lil bit better
void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, ll>> *edges = new vector<pair<int, ll>>[n];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].pb({b, c});
		edges[b].pb({a, c});
	}
	set<pair<ll, int>> pq;
	vector<ll> dist(n, INF);
	dist[0] = 0;
	vector<bool> visited(n);
	vector<int> parent(n, -1);
	pq.insert({0, 0});
	for (int i = 0; i < n; i++) {
		pair<ll, int> top = *pq.begin();
		pq.erase(top);
		int best = top.ss;
		visited[best] = true;
		for (auto i : edges[best]) {
			if ((!visited[i.ff]) && dist[i.ff] > i.ss) {
				pq.erase({dist[i.ff], i.ff});
				dist[i.ff] = i.ss;
				pq.insert({dist[i.ff], i.ff});
				parent[i.ff] = best;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (parent[i] < i) {
			cout << parent[i] << " " << i << " " << dist[i] << nline;
		} else {
			cout << i << " " << parent[i] << " " << dist[i] << nline;
		}
	}
}
