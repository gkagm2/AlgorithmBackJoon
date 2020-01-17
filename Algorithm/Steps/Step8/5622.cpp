#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char word[16]{};

struct Dial {
	short number;
	char alphabet[4];
	Dial(short _number, char spell_1, char spell_2, char spell_3, char spell_4 = '\0') {
		number = _number;
		alphabet[0] = spell_1;
		alphabet[1] = spell_2;
		alphabet[2] = spell_3;
		alphabet[3] = spell_4;
	}

	bool IsInclude(char ch) const {
		for (short i = 0; i < 4; ++i) {
			if (alphabet[i] == ch) {
				return true;
				break;
			}
		}
		return false;
	}

	short GetTime() const {
		return number + 1;
	}
};

// 나가리로 풀어도 되는데 그냥 넣음.
inline void InitDial(vector<Dial> *vec) {
	// 초기화
	vec->push_back(Dial(2, 'A', 'B', 'C'));
	vec->push_back(Dial(3, 'D', 'E', 'F'));
	vec->push_back(Dial(4, 'G', 'H', 'I'));
	vec->push_back(Dial(5, 'J', 'K', 'L'));
	vec->push_back(Dial(6, 'M', 'N', 'O'));
	vec->push_back(Dial(7, 'P', 'Q', 'R', 'S'));
	vec->push_back(Dial(8, 'T', 'U', 'V'));
	vec->push_back(Dial(9, 'W', 'X', 'Y', 'Z'));
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<Dial> vec;

	InitDial(&vec);

	cin.getline(word, 16);
	
	short time = 0;
	for (short i = 0; i < strlen(word); ++i) {
		for (short j = 0; j < vec.size(); ++j) {
			if (vec[j].IsInclude(word[i])) {
				time += vec[j].GetTime();
				break;
			}
		}
	}

	cout << time;

	return 0;
}