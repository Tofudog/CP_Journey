#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 100005;

int n, m;
bool visited[MAX_N] = {false};
int par[MAX_N];
vector<int> graph[MAX_N];

bool bfs() {
	queue<int> q; q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == n) {
			return true;
		}
		for (int c : graph[node]) {
			if (!visited[c]) {
				q.push(c);
				par[c] = node;
				visited[c] = true;
			}
		}
	}

	return false;
}

int main() {
	cin >> n >> m;
	int r1, r2;
	for (int i=0; i<m; i++) {
		cin >> r1 >> r2;
		graph[r1].push_back(r2);
		graph[r2].push_back(r1);
	}
	if (bfs()) {
		//output answers
		vector<int> path;
		path.push_back(n);
		for (int v=par[n]; v!=1; v=par[v]) {
			path.push_back(v);
		}
		path.push_back(1);
		cout << path.size() << '\n';
		for (int i=path.size()-1; i>=0; i--) {
			cout << path[i] << ' ';
		}
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}





// #include <bits/stdc++.h>

// using namespace std;
// const int maxN = 1e5+1;

// int N, M, K, a, b, p[maxN], dist[maxN];
// bool vis[maxN];
// vector<int> G[maxN];
// queue<int> Q;

// int main(){
//     scanf("%d %d", &N, &M);
//     for(int i = 0; i < M; i++){
//         scanf("%d %d", &a, &b);
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }

//     Q.push(1);
//     vis[1] = true;
//     while(!Q.empty()){
//         int u = Q.front(); Q.pop();
//         for(int v : G[u]){
//             if(!vis[v]){
//                 dist[v] = dist[u]+1;
//                 vis[v] = true;
//                 p[v] = u;
//                 Q.push(v);
//             }
//         }
//     }

//     if(!vis[N]){
//         printf("IMPOSSIBLE\n");
//         return 0;
//     }

//     int u = N;
//     K = dist[N];
//     vector<int> ans(K+1);
//     for(int i = K; i >= 0; i--){
//         ans[i] = u;
//         u = p[u];
//     }

//     printf("%d\n", K+1);
//     for(int i = 0; i <= K; i++)
//         printf("%d%c", ans[i], (" \n")[i==K]);
// }







