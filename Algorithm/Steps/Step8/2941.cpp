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
//	while (str[i]) { // ���ڿ��� �ϴ� ������.
//		isFind = false;
//		for (int j = 0; j < 8; ++j) { // ũ�ξ�Ƽ������� üũ
//			if (str[i] == croatiaAlphabet[j][0]) { // ���ڰ� ũ�ξ�Ƽ����� ù ���ڿ� ���ٸ�
//				isCroatia = true;
//				for (a = i + 1, z = 1; z < strlen(croatiaAlphabet[j]); ++z, ++a) { // �� ���������� �Ȱ����� üũ�Ѵ�.
//					if (croatiaAlphabet[j][z] != str[a]) { // ���� �ʴٸ� 
//						isCroatia = false;
//						break;
//					}
//				}
//				if (isCroatia) { // �� ������ �ܾ���� ũ�ξ�Ƽ�ư� �´ٸ� 
//					isFind = true;
//					break;
//				}
//			}
//		}
//
//		if (isFind) { //ã������
//			i = a; // ���� ��ġ�� �̵�
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