#include <iostream>
#include <string>
using namespace std;

struct Time {
	int hour;
	int min;
	int sec;
};

void GetTime(string _strTime, Time& _timeOut) {
	// 시간, 분, 초 분리
	int idx = 0;
	idx = _strTime.find(':');
	int hour = stoi(_strTime.substr(0, idx));
	_strTime = _strTime.substr(idx + 1, _strTime.size() - 1);

	idx = _strTime.find(':');
	int min = stoi(_strTime.substr(0, idx));
	_strTime = _strTime.substr(idx + 1, _strTime.size() - 1);

	idx = _strTime.find(':');
	int sec = stoi(_strTime.substr(0, idx));
	_strTime = _strTime.substr(idx + 1, _strTime.size() - 1);

	_timeOut.hour = hour;
	_timeOut.min = min;
	_timeOut.sec = sec;

}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Time startTime;
	Time endTime;
	string strStartTime, strEndTime;

	cin >> strStartTime;
	cin >> strEndTime;

	GetTime(strStartTime, startTime);
	GetTime(strEndTime, endTime);

	Time time;
	time.sec = endTime.sec - startTime.sec;
	time.min = endTime.min - startTime.min;
	time.hour = endTime.hour - startTime.hour;

	if (time.sec < 0) {
		time.sec += 60;
		--time.min;
	}
	if (time.min < 0) {
		time.min += 60;
		--time.hour;
	}
	if (time.hour <= 0) {
		time.hour += 24;
	}

	string strHour = to_string(time.hour);
	string strMin = to_string(time.min);
	string strSec = to_string(time.sec);

	if (strHour == "0" && strMin == "0" && strSec == "0")
		cout << "24:00:00";
	else {

		int hourI = strHour.size();
		int minI = strMin.size();
		int secI = strSec.size();

		while (hourI < 2) {
			cout << "0";
			++hourI;
		}
		cout << strHour;
		cout << ":";

		while (minI < 2) {
			cout << "0";
			++minI;
		}
		cout << strMin;
		cout << ":";
		while (secI < 2) {
			cout << "0";
			++secI;
		}
		cout << strSec;
	}


	return 0;
}