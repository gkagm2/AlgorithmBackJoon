#include <iostream>
using namespace std;

struct Position {
	int x;
	int y;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Position position[3];
	
	for (int i = 0; i < 3; ++i) { // 입력받는다.
		cin >> position[i].x >> position[i].y;
	}

	if (position[0].x == position[1].x) {
		cout << position[2].x << '\n';
	}
	else if (position[0].x == position[2].x) {
		cout << position[1].x << '\n';

	}
	else if (position[1].x == position[2].x) {
		cout << position[0].x << '\n';

	}

	if (position[0].y == position[1].y) {
		cout << position[2].y << '\n';
	}
	else if (position[0].y == position[2].y) {
		cout << position[1].y << '\n';
	}
	else if(position[1].y == position[2].y){
		cout << position[0].y << '\n';
	}
	
	return 0;
}