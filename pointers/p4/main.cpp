#import <cstdlib>
#import <iostream>
using namespace std;

int main(void) {
  int month = 11;

  const int *pMonth_a = &month;
  // Error: month value can't be changed, it is const int
  //*pMonth_a = 12;

  const int *const pMonth_b = &month;
  const int holliday = 6;
  // pMonth_b = &holliday; // Error: the pointer cannot be reassigned

  int *pYears = new int[10];
  delete[] pYears;
  return 0;
}
