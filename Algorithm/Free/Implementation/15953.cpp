#include <iostream>
#include <vector>
using namespace std;

struct Info{
	int reward;
	int peopleCnt;
};

class Festival {
private:
	vector<Info> list;

public:
	void InsertInfo(const Info& _info) {
		list.push_back(_info);
	}
	
	int GetReward(int _rank) {
		int accPeopleCnt = 0;
		int reward = 0;
		if (_rank == 0)
			return reward;
		for (int i = 0; i < list.size(); ++i) {
			accPeopleCnt += list[i].peopleCnt;
			
			if (_rank - 1 < accPeopleCnt) {
				reward = list[i].reward;
				break;
			}
		}
		return reward;
	}
};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	Festival festivalFirst;
	Festival festivalSecond;
	
	festivalFirst.InsertInfo({ 5000000,1 });
	festivalFirst.InsertInfo({ 3000000,2 });
	festivalFirst.InsertInfo({ 2000000,3 });
	festivalFirst.InsertInfo({ 500000,4 });
	festivalFirst.InsertInfo({ 300000,5 });
	festivalFirst.InsertInfo({ 100000,6 });

	festivalSecond.InsertInfo({ 5120000, 1});
	festivalSecond.InsertInfo({ 2560000, 2});
	festivalSecond.InsertInfo({ 1280000, 4});
	festivalSecond.InsertInfo({ 640000, 8});
	festivalSecond.InsertInfo({ 320000, 16});

	while (testCase--) {
		int rank1, rank2;
		cin >> rank1 >> rank2;
		int reward1 = festivalFirst.GetReward(rank1);
		int reward2 = festivalSecond.GetReward(rank2);

		cout << reward1 + reward2 << "\n";
	}

	return 0;
}