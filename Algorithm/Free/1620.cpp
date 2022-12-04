#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool IsAllnumber(const string& str) {
	bool isAllNumber = true;
	for (int j = 0; j < str.size(); ++j) {
		if (str[j] < '0' || str[j] > '9') {
			isAllNumber = false;
			break;
		}
	}
	return isAllNumber;
}

void Solved1() {
	unordered_map<int, string> m1;
	unordered_map<string, int> m2;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		m1.insert(make_pair(i + 1, str));
		m2.insert(make_pair(str, i + 1));
	}

	for (int i = 0; i < k; ++i) {
		string str;
		cin >> str;
		
		if (IsAllnumber(str)) {
			cout << m1[stoi(str)] << "\n";
		}
		else
			cout << m2[str] << "\n";
	}
}

void Solved2() {
	unordered_map<int, string> m;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		m.insert(make_pair(i + 1, str));
	}

	for (int i = 0; i < k; ++i) {
		string str;
		cin >> str;
		bool isAllNumber = true;
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] < '0' || str[j] > '9') {
				isAllNumber = false;
				break;
			}
		}

		if (isAllNumber) {
			int num = stoi(str);
			cout << m[num] << "\n";
		}
		else {
			for (auto const& val : m) {
				if (val.second == str) {
					cout << val.first << "\n";
				}
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solved1();
	// Solved2(); // 시간초과

	return 0;
}

