#import <cstdlib>
#import <iostream>
using namespace std;

int main(void) {

  int *lottery = new int[6];

  for (int i = 0; i < 6; ++i) {
    lottery[i] = rand() % 100;
    cout << lottery[i] << endl;
  }

  delete[] lottery;

  return 0;
}
