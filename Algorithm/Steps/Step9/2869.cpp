#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int treeHeight; // �ö󰡾� �� ���� ���� V
	int climbingHeight; // ���� �ö� �� �ִ� ���� A
	int  slidingHeight; // �̲������� ���� B
	int  dayCount; // ���� �ɸ�����

	cin >> climbingHeight >> slidingHeight >> treeHeight;
	dayCount = (treeHeight - slidingHeight - 1) / (climbingHeight - slidingHeight) + 1;
	cout << dayCount;
	return 0;
}

// �ݺ������� Ǯ���� �� (�ð��ʰ�)
//#include <iostream>
//using namespace std;
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	int treeHeight; // �ö󰡾� �� ���� ���� V
//	int climbingHeight; // ���� �ö� �� �ִ� ���� A
//	int slidingHeight; // �̲������� ���� B
//	int dayCount = 0; // ���� �ɸ�����
//	int currentHeight = 0; // ���� ����
//
//	cin >> climbingHeight >> slidingHeight >> treeHeight;
//
//	while (true) {
//		++dayCount;
//
//		currentHeight += climbingHeight; // �� �ð��� ��
//		if (currentHeight >= treeHeight)
//			break;
//
//		currentHeight -= slidingHeight; // �� �ð��� �� 
//	}
//	cout << dayCount;
//
//	return 0;
//}