#include <iostream>
using namespace std;

bool* primeArr = new bool[1000001];

inline void Eratos() {
	for (int i = 2; i <= 1000000; i++)
		primeArr[i] = true;

	for (int i = 2; i * i <= 1000000; i++)
	{
		if (primeArr[i])
			for (int j = i * i; j <= 1000000; j += i)
				primeArr[j] = false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	Eratos();

	for (int i = 0; i < 100000; ++i) {
		cin >> num;
		if (num == 0)
			break;

		bool chk = false;
		for (int j = 3; j <= num; j += 2)
			if (primeArr[j] && primeArr[num - j])
			{
				cout << num << " = " << j << " + " << num - j << '\n';
				chk = true;
				break;
			}
		if (!chk)
			cout << "Goldbach's conjecture is wrong.";
	}

	delete[] primeArr;
	return 0;
}