#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	int n;
	cin >> t;
	while (t--) {
		cin >> n;

		int csum = 0;
		float gsum = 0;
		
		for (int i = 0; i < n; ++i) {
			int c;
			float g;
			
			cin >> c >> g;
			csum += c;
			gsum += (c * g);
		}
		
		cout << csum << " " << roundf(10.f * gsum / csum) / 10.f << "\n";
	}

	return 0;
}