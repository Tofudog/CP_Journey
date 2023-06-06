#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = (int)1e5 + 10;

int n, m;
vector<int> graph[MAX_N];
int teams[MAX_N];
bool visited[MAX_N] = {false};

bool impossible = false;
void dfs(int k, int T) {
	if (visited[k]) {
		if (teams[k] != T) {impossible = true;}
		return;
	}
	visited[k] = true;
	teams[k] = T;
	for (int c : graph[k]) {
		if (T==1) {dfs(c, 2);}
		else {dfs(c, 1);}
	}
}

int main() {
	cin >> n >> m;
	int f1, f2;
	for (int i=0; i<m; i++) {
		cin >> f1 >> f2;
		graph[f1].push_back(f2);
		graph[f2].push_back(f1);
	}
	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			dfs(i, 1);
		}
	}
	if (impossible) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		for (int i=1; i<=n; i++) {cout << teams[i] << ' ';}
	}
}