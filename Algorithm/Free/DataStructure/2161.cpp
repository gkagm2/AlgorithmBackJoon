#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	deque<int> dq;

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		dq.push_back(i);
	}

	while (!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
		if (dq.empty())
			break;
		dq.push_back(dq.front());
		dq.pop_front();
	}
	
	return 0;
}