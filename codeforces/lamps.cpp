#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int t; cin >>t ;
	while (t--) {
		vector<int> x[200005];
		int n; cin >> n;
		for (int i=0; i<n; i++) {
			ll a, b; cin >> a >> b;
			x[a].push_back(b);
		}
		ll ans = 0;
		for (int i=1; i<=n; i++) {
			sort(x[i].rbegin(), x[i].rend());
			for (int j=0; j<=i&&j<x[i].size(); j++) {
				ans += x[i][j];
			}
		}
		cout << ans << '\n';
	}
}