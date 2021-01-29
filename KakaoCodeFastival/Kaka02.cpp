#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

struct CourseMenu {
	int ordersIdx;
	int cnt;
};

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	map<string, CourseMenu> mp;

	for (int i = 0; i < course.size(); ++i) {
		int courseSize = course[i];

		for (int oi = 0; oi < orders.size(); ++oi) {
			if (orders[oi].size() >= courseSize) {
				for (int j = 0; j < orders[oi].size() - courseSize; ++j) { // 문자열 비교
					string name = orders[oi].substr(j, courseSize);
					
					auto it = mp.find(name);
					if (it == mp.end()) {
						CourseMenu cMenu;
						cMenu.ordersIdx = oi;
						cMenu.cnt = 1;
						mp.insert(make_pair(name, cMenu));
					}
					else {
						CourseMenu &cMenu = it->second;
						if (cMenu.ordersIdx != oi) {
							++cMenu.cnt;
						}
					}
				}
			}
		}

		for (auto it : mp) {
			if (it.second.cnt > 1) {
				answer.push_back(it.first);
			}
		}
		mp.clear();
	}

	return answer;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<string> orders;
	orders.push_back("ABCFG");
	orders.push_back("AC");
	orders.push_back("CDE");
	orders.push_back("ACDE");
	orders.push_back("BCFG");
	orders.push_back("ACDEH");

	vector<int> course;
	course.push_back(2);
	course.push_back(3);
	course.push_back(4);

	vector<string> s = solution(orders, course);

	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << "\n";
	}


	return 0;
}