#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long a, b, c, d;

	cin >> a >> b >> c >> d;

	string a1;
	string a2; 

	a1 = to_string(a);
	a2 = to_string(b);
	a = stoll(a1 + a2);

	a1 = std::to_string(c);
	a2 = std::to_string(d);
	b = stoll(a1 + a2);

	cout << a + b;

	return 0;
}