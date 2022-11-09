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
	if (str == "������ ����� ����")
		isStart = true;

	queue<int> q;
	while (isStart) {
		string answer;
		getline(cin, answer);

		if (answer == "������ ����� ��") {
			isStart = false;
			continue;
		}
		if (answer == "������") {
			if (q.empty()) {
				q.push(1);
				q.push(1);
			}
			else
				q.pop();
		}
		else if (answer == "����")
			q.push(1);
	}

	if (q.empty())
		cout << "�������� �����";
	else
		cout << "����";

	return 0;
}