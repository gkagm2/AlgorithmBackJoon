#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	vector<string> vec(cnt);

	while (cnt--) {
		string word;
		cin >> word;
		vec.push_back(word);
	}

	sort(vec.begin(), vec.end(), [](string& a, string& b) {
		if (a.size() == b.size()) {
			return a < b;
		}
		else {
			return a.size() < b.size();
		}
	});

	string prebWord;
	for (int i = 0; i < vec.size(); ++i) {
		if (prebWord == vec[i])
			continue;
		cout << vec[i] << '\n';
		prebWord = vec[i];
	}

	return 0;
}
