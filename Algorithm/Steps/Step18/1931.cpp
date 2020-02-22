#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Conference {
	int beginTime;
	int endTime;
};

bool Compare(const Conference c1, const Conference c2) {
	if (c1.endTime == c2.endTime) {
		return c1.beginTime < c2.beginTime;
	}
	else {
		return c1.endTime < c2.endTime;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<Conference> vec(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i].beginTime >> vec[i].endTime;
	}
	

	sort(vec.begin(), vec.end(), Compare);

	int cnt = 0;
	int endTime = 0;

	for (int i = 0; i < vec.size(); ++i) {
		if (endTime <= vec[i].beginTime) {
			endTime = vec[i].endTime;
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}