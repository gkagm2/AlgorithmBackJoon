#include <iostream>
#include <string>
using namespace std;


int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string strGrade[] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D+","D0","D-","F"};
  string strGradeNum[] = {"4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","1.3","1.0","0.7","0.0"};
  
  
  string input;
  cin >> input;
  int iSize = sizeof(strGrade) / sizeof(int);
  
  for(int i=0 ;i < iSize;++i) {
    if(strGrade[i] == input){
      cout << strGradeNum[i];
      break;
    }
  }
  
  return 0;
}
