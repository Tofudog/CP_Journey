#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = (int)1e5 + 10;

int n, m;
vector<int> graph[MAX_N];
bool visited[MAX_N];
int path[MAX_N];

bool bfs(k) {
	queue<int> q; q.push(k);
	visited[k] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int c : graph[node]) {
			if (visited[c]) {
				if (path[node] != c) {
					//this means not a parent, so cycle is discovered
					//print out solution in reversed fashion...

					
					return true;
				}
			}
			else {
				path[c] = node;
				visited[c] = true;
				q.push(c);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int c1, c2;
	for (int i=0; i<m; i++) {
		cin >> c1 >> c2;
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
	}
	//make sure to go through each component
	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			if (bfs(i)) {
				return 1;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}