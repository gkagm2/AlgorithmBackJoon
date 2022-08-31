#include <iostream>
#include <string>
using namespace std;

class Calculator {
public:
	float Calculate(float _num, const string&  _c);
};

float Calculator::Calculate(float _num, const string&  _c)
{
	for (int i = 0; i < _c.size(); ++i) {
		char c = _c[i];

		if (c == '@')
			_num *= 3.f;
		else if (c == '%')
			_num += 5.f;
		else if (c == '#')
			_num -= 7.f;
	}
	return _num;
}



int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	Calculator cal;

	while (t--) {
		float num;
		cin >> num;
		string c;
		getline(cin, c);

		float result = cal.Calculate(num, c);

		cout << fixed;
		cout.precision(2);
		cout << result << "\n";
	}

	return 0;
}
