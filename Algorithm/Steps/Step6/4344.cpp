#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int caseCount;
	
	int studentCount;
	int *studentScore;

	int total;
	float avg;
	int countAboveAvg;

	cout << fixed;
	cout.precision(3);

	// Case �Է�
	cin >> caseCount;

	for (int i = 0; i < caseCount; ++i) {
		cin >> studentCount; // �л� �� �Է�
		studentScore = new int[studentCount];

		total = 0;
		avg = 0;
		countAboveAvg = 0;

		for (int j = 0; j < studentCount; ++j) { // �л� ���� �Է�
			cin >> studentScore[j];
			total += studentScore[j];
		}

		avg = total / (float)studentCount;

		// Check count
		for (int j = 0; j < studentCount; ++j) {
			if (avg < studentScore[j]) {
				++countAboveAvg;
			}
		}
		avg = (float)countAboveAvg / studentCount * 100;
		
		cout << avg << "%" << '\n';

		delete[] studentScore;
	}

	return 0;
}