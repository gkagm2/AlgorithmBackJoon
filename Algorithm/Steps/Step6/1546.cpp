#include <iostream>
using namespace std;

int main() { // 배열 문제지만 배열 안쓰는 클라뜌~ 삐뚤어질거얌
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int subjectCount;

	float highestScore = 0;
	float totalScore = 0;
	float avg = 0;


	cout << fixed;
	cout.precision(6);
	cin >> subjectCount;

	float *score = new float[subjectCount] {0};


	for (int i = 0; i < subjectCount; ++i) {
		
		cin >> score[i];
		if (score[i] > highestScore) {
			highestScore = score[i];
		}
	}

	for (int i = 0; i < subjectCount; ++i) {
		score[i] = score[i] / highestScore * 100;
		totalScore += score[i];
	}

	avg = totalScore / subjectCount;

	cout << avg;

	delete[]score;

	return 0;
}