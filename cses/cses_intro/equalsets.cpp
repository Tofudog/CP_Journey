#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	if (n%2 == 0) {
		if ( (n/2)%2 != 0 ) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			cout << n/2 << '\n';
			for (int i=1; i<n/2; i+=2) {cout << i << ' ';}
			for (int i=n; i>n/2; i-=2) {cout << i << ' ';}
			cout << n/2 << '\n';
			for (int i=2; i<=n/2; i+=2) {cout << i << ' ';}
			for (int i=n-1; i>=n/2; i-=2) {cout << i << ' ';}
		}
	}
	else {
		ll target = 0;
		for (ll i=1; i<=n; i++) {target += i;}
		if (target%2 == 1) {cout << "NO\n";}
		else {
			target /= 2;
			ll curr = 0; set<ll> group1; ll a = n;
			while (curr != target) {
				if (curr + a > target) {
					group1.insert(target - curr);
					break;
				}
				group1.insert(a); curr += a; --a;
			}
			cout << "YES\n";
			cout << group1.size() << '\n';
			for (int num : group1) {
				cout << num << ' ';
			}
			cout << '\n';
			cout << n - group1.size() << '\n';
			for (int i=1; i<=n; i++) {
				if (!group1.count(i)) {cout << i << ' ';}
			}
		}
	}
	return 0;
}