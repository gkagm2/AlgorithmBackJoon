#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		deque<char> dq;
		string keyLog;
		cin >> keyLog;
		int cur = 0;
		for (int i = 0; i < keyLog.size(); ++i) {
			switch (keyLog[i]) {
			case '<':
				if (dq.empty() || cur ==0)
					continue;
				--cur;
				break;
			case '>':
				if (dq.size() == cur)
					continue;
				++cur;
				break;
			case '-': {
				if (cur == 0)
					continue;
				auto iter = dq.begin() + cur -1;
				dq.erase(iter);
				--cur;
			}
				
				break;
			default: {
				auto iter = dq.begin() + cur;
				dq.insert(iter, keyLog[i]);
				++cur;
			}
				break;
			}
		}

		for (auto x : dq) {
			cout << x;
		}
		cout << "\n";
	}

	return 0;
}