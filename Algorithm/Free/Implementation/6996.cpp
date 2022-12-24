#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--) {
		string strFirst;
		string strSecond;
		
		cin >> strFirst >> strSecond;

		bool isAnagrams = true;

		if (strFirst.size() != strSecond.size())
			isAnagrams = false;
		else {
			vector<int> v1, v2;
			v1.resize(strFirst.size(), 1);
			v2.resize(strSecond.size(), 1);

			for (int i = 0; i < v1.size(); ++i) {
				bool bFind = false;
				for (int j = 0; j < v2.size(); ++j) {
					if (strFirst[i] == strSecond[j] &&
						v1[i] == 1 && v2[j] == 1) {
						v1[i] = v2[j] = 0;
						bFind = true;
					}

					if (bFind)
						break;
				}
				if (v1[i] == 1) {
					isAnagrams = false;
					break;
				}
			}
		}
		
		if (isAnagrams)
			cout << strFirst << " & " << strSecond << " are anagrams.\n";
		else
			cout << strFirst << " & " << strSecond << " are NOT anagrams.\n";
	}
	

	return 0;
}