#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<string> vecMemStr;
	vector<string> vecMemSecStr;

	for (int k = 0; k < n; ++k) {
		string str;
		cin >> str;
		string strdoubble = "";
		for (int i = 0; i < m; ++i)
			strdoubble = strdoubble + str[i] + str[i];
		vecMemStr.push_back(strdoubble);
	}

	for (int k = 0; k < n; ++k) {
		string strsec = "";
		cin >> strsec;
		vecMemSecStr.push_back(strsec);
	}

	bool isSame = true;
	for (int i = 0; i < vecMemStr.size(); ++i) {
		if (vecMemStr[i] != vecMemSecStr[i]) {
			isSame = false;
			break;
		}
	}
	
	if (isSame)
		cout << "Eyfa";
	else cout << "Not Eyfa";

	return 0;
}