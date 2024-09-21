#include <iostream>

using namespace std;

/* 
* Output:
* Pointer content: 0x16f4bb258
* Pointer ref value: 29 
* Updated pointer ref value: 30
* Updated value: 30
*/ 
int main(void){
  int day = 29;
  int* pDay = &day;

  cout << "Pointer content: " << pDay << endl;
  cout << "Pointer ref value: " << *pDay << endl;

  *pDay = 30;

  cout << "Updated pointer ref value: " << *pDay << endl;
  cout << "Updated value: " << day << endl;
  return 0;
}

