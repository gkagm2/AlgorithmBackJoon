#include <iostream>
using namespace std;

/*
���������� for�� ������ Ǯ�� ���� �����ؾ� �� ���� �ִ�. 
����� ����� ������ ���� ���� �Է¹ްų� ����� �� �ð��ʰ��� �� �� �ִٴ� ���̴�.

C++�� ����ϰ� �ְ� cin/cout�� ����ϰ��� �Ѵٸ�, 
cin.tie(NULL)�� sync_with_stdio(false)�� �� �� ������ �ְ�, 
endl ��� ���๮��(\n)�� ����. 
��, �̷��� �ϸ� �� �̻� scanf/printf/puts/getchar/putchar �� C�� ����� ����� ����ϸ� �� �ȴ�.
*/
int main() {
	cin.tie(NULL);				
	ios::sync_with_stdio(false);

	int count;
	int a, b;
	cin >> count;

	for (int i = 0; i < count; ++i) {
		cin >> a;
		cin >> b;
		cout << a + b << '\n';
	}

	return 0;
}