#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {
		ll r, c; cin >> r >> c;
		//determine whether L or R box
		//ll boxn = (r >= c) ? (r : c); --boxn;
		ll boxn; if (r>=c) {boxn=r;} else {boxn=c;}
		--boxn;
		//cout << "The boxn is " << boxn << '\n';
		bool isLeft = (boxn % 2 == 1);
		if (isLeft) {
			//cout << "this is a left box\n";
			cout << boxn*boxn + r + (boxn+1 - c);
		} else {
			cout << boxn*boxn + c + (boxn+1 - r);
		}
		cout << '\n';
	}
}