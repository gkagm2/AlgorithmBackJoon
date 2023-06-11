#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int size;
	vector<int> vec;
	
	cin >> size;
	vec.resize(size);

	for (int i = 0; i < size; ++i) {
		int n;
		cin >> n;
		vec[i] = n;
	}

	int v;
	cin >> v;

	int cnt = 0;
	vector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
		if (*iter == v)
			++cnt;

	cout << cnt;

	return 0;
}