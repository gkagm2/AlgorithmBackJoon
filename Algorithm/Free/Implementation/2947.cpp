#include <iostream>
#include <algorithm>
using namespace std;

int ar[5];
void Print() {
	for (int i = 0; i < 5; ++i)
		cout << ar[i] << " ";
	cout << "\n";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	
	for (int i = 0; i < 5; ++i)
		cin >> ar[i];

	while (true) {
		bool isChanged = false;
		for (int i = 0; i < 4; ++i) {
			if (ar[i] > ar[i + 1]) {
				isChanged = true;
				swap(ar[i], ar[i + 1]);
				Print();
			}
		}
		bool isDone = true;
		for (int i = 0; i < 5; ++i) {
			if (i + 1 != ar[i]) {
				isDone = false;
				break;
			}
		}
		if (isDone)
			break;
	}
	
	return 0;
}