#include <iostream>

using namespace std;

/**
 * Executed in 64bit architecure address size is 64 bits (8B).
 *
 * int size: 4
 * pointer to int size: 8
 * char size: 1
 * pointer to char size: 8
 * double size: 8
 * pointer to double size: 8
 */
int main(void) {
  int age = 19;
  char grade = 'A';
  double height = 1.72;

  int *pAge = &age;
  char *pGrade = &grade;
  double *pHeight = &height;

  cout << "int size: " << sizeof(age) << endl;
  cout << "pointer to int size: " << sizeof(pAge) << endl;
  cout << "char size: " << sizeof(grade) << endl;
  cout << "pointer to char size: " << sizeof(pGrade) << endl;
  cout << "double size: " << sizeof(height) << endl;
  cout << "pointer to double size: " << sizeof(pHeight) << endl;

  return 0;
}
