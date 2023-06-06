#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n; cin >> n;
	for (ll k=1; k<=n; k++) {
		ll C = (k*k*k*k - k*k)/2;
		ll E = 4*(k-2)*(k-1);
		cout << C-E << '\n';
	}
	return 0;
}