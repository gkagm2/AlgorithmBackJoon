#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_CAR_CNT 3

struct Car {
	int inTime;
	int outTime;
};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	Car car[MAX_CAR_CNT] = {};
	int cost[MAX_CAR_CNT + 1] = {};
	for (int i = 1; i < MAX_CAR_CNT + 1; ++i)
		cin >> cost[i];

	int inTime, outTime;
	for (int i = 0; i < MAX_CAR_CNT; ++i) {
		cin >> inTime >> outTime;
		car[i].inTime = inTime;
		car[i].outTime = outTime;
	}

	// Check
	int maxParkTime = 0;
	for (int i = 0; i < MAX_CAR_CNT; ++i) {
		car[i].outTime;
		maxParkTime = max(maxParkTime, car[i].outTime);
	}

	int totalCost = 0;
	for (int curTime = 1; curTime <= maxParkTime; ++curTime) {

		int duplicateCnt = 0;
		for (int j = 0; j < MAX_CAR_CNT; ++j) {
			if (car[j].inTime <= curTime && car[j].outTime > curTime)
				++duplicateCnt;
		}
		totalCost += duplicateCnt * cost[duplicateCnt];
	}

	cout << totalCost;

	return 0;
}