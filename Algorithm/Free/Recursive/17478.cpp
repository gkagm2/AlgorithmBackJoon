#include <iostream>
#include <string>
using namespace std;

int n;

void Func(int cnt, int callCnt) {
	string str = "";
	for (int i = 0; i < callCnt; ++i)
		str += "____";
	
	cout << str <<  "\"����Լ��� ������?\"\n";
	if (cnt <= 0) {
		cout << str << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		cout << str << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << str << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		cout << str << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		Func(cnt - 1, callCnt + 1);
	}
	cout << str << "��� �亯�Ͽ���.";
	if (cnt != n)
		cout << "\n";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	Func(n, 0);
	
	return 0;
}