#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	int box[100];

	for (int i = 0; i < 100; ++i)
		box[i] = i + 1;

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		
		int temp = box[n1 - 1];
		box[n1 - 1] = box[n2 - 1];
		box[n2 - 1] = temp;
	}

	for (int i = 0; i < n; ++i)
		cout << box[i] << " ";

	return 0;
}