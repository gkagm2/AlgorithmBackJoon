#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;
	getline(cin, str);

	bool isStart = false;
	if (str == "고무오리 디버깅 시작")
		isStart = true;

	queue<int> q;
	while (isStart) {
		string answer;
		getline(cin, answer);

		if (answer == "고무오리 디버깅 끝") {
			isStart = false;
			continue;
		}
		if (answer == "고무오리") {
			if (q.empty()) {
				q.push(1);
				q.push(1);
			}
			else
				q.pop();
		}
		else if (answer == "문제")
			q.push(1);
	}

	if (q.empty())
		cout << "고무오리야 사랑해";
	else
		cout << "힝구";

	return 0;
}