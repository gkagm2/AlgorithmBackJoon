#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();

    vector<int> vec;

    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();
        vec.push_back(pi);
    }

    sort(vec.begin(), vec.end());

    int offset = 10000000;
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (abs(vec[i] - vec[i + 1]) < offset)
            offset = abs(vec[i] - vec[i + 1]);
    }

    cout << offset << endl;
}