#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
stack<char> stk;
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string s1, s2;

	cin >> s1 >> s2;
	
	if (s1.size() < s2.size())
		swap(s1, s2);

	string zero = "";
	int difLen = s1.size() - s2.size();
	for (int i = 0; i < difLen; ++i) {
		zero += '0';
	}
	s2 = zero + s2;
	
	int val = 0;
	int etc = 0;
	for (int i = s1.size() - 1; i >= 0; --i) {
		int a1, a2;
		a1 = (s1[i] - '0');
		a2 = (s2[i] - '0');

		etc = (a1 + a2 + val) % 10;
		val = (a1 + a2 + val) / 10;
		
		stk.push(etc + '0');
	}
	if (val > 0)
		stk.push(val + '0');

	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}

	return 0;
}