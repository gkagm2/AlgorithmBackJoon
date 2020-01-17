#include <stdio.h>

int main() {
	char str[101] , i, count;
	i = count = 0;

	scanf("%s", str);
	
	while (str[i]) {
		++count;
		if ((str[i] == 'c' && str[i + 1] == '=' || str[i] == 'c' && str[i + 1] == '-')||
			(str[i] == 'l' && str[i + 1] == 'j')||
			(str[i] == 'n' && str[i + 1] == 'j')||
			(str[i] == 's' && str[i + 1] == '=')||
			(str[i] == 'z' && str[i + 1] == '=')||
			(str[i] == 'd' && str[i + 1] == '-')) {
			i += 2;
		}
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
			i += 3;
		}
		else {
			++i;
		}
	}
	printf("%d",count);

	return 0;
}

//   Old version
//int main() {
//	char croatiaAlphabet[8][4] {
//		{"c="},
//		{"c-"},
//		{"dz="},
//		{"d-"},
//		{"lj"},
//		{"nj"},
//		{"s="},
//		{"z="},
//	};
//
//	char str[101];
//	int a;
//	int z;
//	bool isCroatia;
//	bool isFind;
//	short alphabetCount = 0;
//
//	cin.getline(str, 101);
//
//	int i = 0;
//	while (str[i]) { // 문자열을 싹다 돌린다.
//		isFind = false;
//		for (int j = 0; j < 8; ++j) { // 크로아티비아인지 체크
//			if (str[i] == croatiaAlphabet[j][0]) { // 문자가 크로아티비아의 첫 글자와 같다면
//				isCroatia = true;
//				for (a = i + 1, z = 1; z < strlen(croatiaAlphabet[j]); ++z, ++a) { // 맨 마지막까지 똑같은지 체크한다.
//					if (croatiaAlphabet[j][z] != str[a]) { // 같지 않다면 
//						isCroatia = false;
//						break;
//					}
//				}
//				if (isCroatia) { // 맨 마지막 단어까지 크로아티아가 맞다면 
//					isFind = true;
//					break;
//				}
//			}
//		}
//
//		if (isFind) { //찾았으면
//			i = a; // 다음 위치로 이동
//		}
//		else {
//			++i;
//		}
//		++alphabetCount;
//	}
//
//	cout << alphabetCount;
//
//	return 0;
//}