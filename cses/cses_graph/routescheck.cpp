#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = (int)1e5 + 10;

int n, m;
vector<int> reach[MAX_N][2];
bool visited[MAX_N] = {false};

void dfs(int k, x) {
	if (visited[k][x]) {return;}
	visited[k][x] = true;
	for (int c : reach[k][x]) {
		dfs(c, x);
	}
}

int main() {
	cin >> n >> m;
	int to, from;
	for (int i=0; i<m; i++) {
		cin >> to >> from;
		reach[0][to].push_back(from);
		reach[1][from].push_back(to);
	}
	dfs(1, 0);
	//check if there's a vertex that can't be reached by initial
	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			cout << "NO\n";
			cout << 1 << ' ' << i;
			return 0;
		}
	}
	memset() // all to be false again...
	dfs(1, 1);
	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			cout << "NO\n";
			cout << i << ' ' << 1;
			return 0;
		}
	}
	cout << "YES\n";
	//return 1;
}