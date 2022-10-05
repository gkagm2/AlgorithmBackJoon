#include <iostream>
#include <vector>
using namespace std;

void Swap(int& _a, int& _b) {
	int t = _a; 
	_a = _b;
	_b = t;
}

void BubbleSort(vector<int>& _vecNums, int _swapCheckCnt, vector<int>& _retSwapNums) {
	int swapCnt = 0;
	for (int last = _vecNums.size() - 1; last >= 1; --last) {
		for (int j = 0; j <= last - 1; ++j) {
			if (_vecNums[j] > _vecNums[j + 1]) {
				Swap(_vecNums[j], _vecNums[j + 1]);
				++swapCnt;
				if (swapCnt == _swapCheckCnt) {
					_retSwapNums.push_back(_vecNums[j]);
					_retSwapNums.push_back(_vecNums[j + 1]);
				}
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<int> ans;

	vector<int> nums;
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	BubbleSort(nums, m, ans);

	if (0 == ans.size())
		cout << -1;
	else
		cout << ans[0] << " " << ans[1];

	return 0;
 }
