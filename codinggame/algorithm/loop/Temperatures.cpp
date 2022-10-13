#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vecTemp;
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    int answer = 0;
    int min = 10000;
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();

        vecTemp.push_back(t);
    }

    sort(vecTemp.begin(), vecTemp.end());

    for (int i = 0; i < vecTemp.size(); ++i) {
        int tt = abs(vecTemp[i]);
        if (min >= tt) {
            answer = vecTemp[i];
            min = tt;
        }
    }

    cout << answer << endl;
}