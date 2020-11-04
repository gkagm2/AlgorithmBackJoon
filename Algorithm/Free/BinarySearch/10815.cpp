#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &vec, int size, int num) {
	bool isFind = false;
	int left = 0;
	int right = size;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (vec[mid] == num) {
			isFind = true;
			break;
		}

		if (vec[mid] < num) {
			left = mid + 1;
		}
		else {
			right = mid -1;
		}
	}
	return isFind == true ? 1 : 0;
}


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<int> vec;


	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int cardNum;
		cin >> cardNum;
		vec.push_back(cardNum);
	}

	sort(vec.begin(), vec.end());


	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int findNum;
		cin >> findNum;
		cout << BinarySearch(vec, n, findNum) << " ";
	}

	return 0;
}