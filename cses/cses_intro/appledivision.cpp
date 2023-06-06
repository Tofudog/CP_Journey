#include <iostream>
using namespace std;
using ll = long long;
const long long MAX_D = 20 * 1e9 + 5;

ll p[21]; int n;
ll minD = MAX_D;
ll X = 0;

void combination(int i, ll y) {
	if (i == n) {
		//calculate the group diff
		ll g1 =  y;
		ll g2 = X-y;
		if (minD > abs(g1-g2)) {
			minD = abs(g1-g2);
		}
		return;
	}
	combination(i+1, y);
	combination(i+1, y+p[i]);
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {cin >> p[i]; X += p[i];}
	combination(0, 0);
	cout << minD << '\n';
}