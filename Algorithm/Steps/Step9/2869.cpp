#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int treeHeight; // 올라가야 할 나무 높이 V
	int climbingHeight; // 낮에 올라갈 수 있는 높이 A
	int  slidingHeight; // 미끄러지는 높이 B
	int  dayCount; // 몇일 걸리는지

	cin >> climbingHeight >> slidingHeight >> treeHeight;
	dayCount = (treeHeight - slidingHeight - 1) / (climbingHeight - slidingHeight) + 1;
	cout << dayCount;
	return 0;
}

// 반복문으로 풀었을 때 (시간초과)
//#include <iostream>
//using namespace std;
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	int treeHeight; // 올라가야 할 나무 높이 V
//	int climbingHeight; // 낮에 올라갈 수 있는 높이 A
//	int slidingHeight; // 미끄러지는 높이 B
//	int dayCount = 0; // 몇일 걸리는지
//	int currentHeight = 0; // 현재 높이
//
//	cin >> climbingHeight >> slidingHeight >> treeHeight;
//
//	while (true) {
//		++dayCount;
//
//		currentHeight += climbingHeight; // 낮 시간일 때
//		if (currentHeight >= treeHeight)
//			break;
//
//		currentHeight -= slidingHeight; // 밤 시간일 때 
//	}
//	cout << dayCount;
//
//	return 0;
//}