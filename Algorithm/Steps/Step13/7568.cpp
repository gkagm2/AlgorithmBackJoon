#include <iostream>
using namespace std;

struct Human {
	int kg;
	int cm;
	int priority;
	Human() : priority(1) {}

	bool operator<(Human &h) {
		if (kg < h.kg && cm < h.cm) {
			return true;
		}
		return false;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Human human[50];

	int cnt;

	// Input
	cin >> cnt;
	for (int i = 0; i < cnt; ++i) {
		cin >> human[i].kg;
		cin >> human[i].cm;
	}
	
	for (int i = 0; i < cnt; ++i) {
		int hmCnt = 0;
		for (int j = 0; j < cnt; ++j) {
			if (human[i] < human[j] && i != j) {
				++human[i].priority;
			}
		}
	}

	for (int i = 0; i < cnt; ++i) {
		cout << human[i].priority << " ";
	}

	return 0;
}