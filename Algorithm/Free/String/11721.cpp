#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string n;

	cin >> n;
	
	for (int i = 0; i < n.size(); ++i) {
		cout << n[i];
		if ((i + 1) % 10 == 0)
			cout << "\n";
	}
	return 0;
}