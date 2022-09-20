#include <iostream>
#include <vector>
using namespace std;
#define PENGUIN -1
#define INT_MAX 2147483647
struct Floor {
	int num;
};

int FindPenguinPosition(const vector<Floor>& _vecFloor);
int Solved(const vector<Floor>& _vecFloor);

int Solved(const vector<Floor>& _vecFloor) {
	int penguinPos = FindPenguinPosition(_vecFloor);

	int minValue = INT_MAX;

	int leftMinValue = INT_MAX;
	for (int l = 0; l <= penguinPos - 1; ++l) {
		if (_vecFloor[l].num < leftMinValue)
			leftMinValue = _vecFloor[l].num;
	}

	int rightMinValue = INT_MAX;
	for (int r = penguinPos + 1; r < _vecFloor.size(); ++r) {
		if (_vecFloor[r].num < rightMinValue)
			rightMinValue = _vecFloor[r].num;
	}

	minValue = leftMinValue + rightMinValue;

	return minValue;
}

int FindPenguinPosition(const vector<Floor>& _vecFloor) {
	int penguinPos = 0;
	for (int i = 0; i < _vecFloor.size(); ++i) {
		if (_vecFloor[i].num == PENGUIN) {
			penguinPos = i;
			break;
		}
	}

	return penguinPos;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int floorCnt;

	cin >> floorCnt;
	vector<Floor> vecFloor;

	for (int i = 0; i < floorCnt; ++i) {
		Floor floor;
		cin >> floor.num;
		vecFloor.push_back(floor);
	}

	int answer = Solved(vecFloor);
	cout << answer;

	return 0;
}