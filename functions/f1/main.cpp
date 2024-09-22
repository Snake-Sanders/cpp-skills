#include <iostream>

using namespace std;

void inc_reference(int &value) { value++; }
void inc_pointer(int *value) { (*value)++; }

int main(void) {
  int day = 20;

  inc_reference(day);
  cout << "incremented by reference: " << day << endl;

  inc_pointer(&day);
  cout << "incremented by pointer: " << day << endl;

  return 0;
}
