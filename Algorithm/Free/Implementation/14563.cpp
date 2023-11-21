#include <iostream>
#include <vector>
using namespace std;

void GetDivisor(vector<int>& _vecVals, int _num) {
    for (int i = 1; i < (_num / 2) + 1; ++i) {
        if (_num % i == 0) {
            _vecVals.push_back(i);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        vector<int> v;

        GetDivisor(v, input);

        int sum = 0;
        for (int j = 0; j < v.size(); ++j) {
            sum += v[j];
        }

        if (sum == input) {
            cout << "Perfect\n";
        }
        else if (sum < input) {
            cout << "Deficient\n";
        }
        else {
            cout << "Abundant\n";
        }
    }

    return 0;
}
