// stable sort
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct info {
	int age;
	string name;
};
bool Cmp(const info &a,const info &b) {
	return a.age < b.age;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<info> v;

	for (int i = 0; i < n; ++i) {
		info member;
		cin >> member.age >> member.name;
		v.push_back(member);
	}
	stable_sort(v.begin(), v.end(), Cmp);
	
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].age << " " << v[i].name << "\n";
	}

	return 0;
}