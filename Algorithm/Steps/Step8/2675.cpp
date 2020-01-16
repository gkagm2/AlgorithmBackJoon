#include <iostream>
using namespace std;

#define MAX_SIZE 21

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int caseCount;
	
	cin >> caseCount;

	int repetitionCount;
	char str[MAX_SIZE];

	while (caseCount > 0) {
		cin >> repetitionCount;
		cin.ignore(MAX_SIZE, ' ');
		cin.getline(str, MAX_SIZE);
		
		int i = 0;
		while (str[i] != '\0') {
			for (int j = 0; j < repetitionCount; ++j) {
				cout << str[i];
			}
			++i;
		}
		cout << '\n';
		--caseCount;
	}

	return 0;
}