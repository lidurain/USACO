/*
ID: rainywa1
PROG: combo
LANG: C++11
*/

#include <fstream>
#include <ostream>
#include <vector>

using namespace std;

int main(){
  ifstream fin("combo.in");
  ofstream fout("combo.out");
  int N;
  fin >> N;
  std::vector<int> lock1(3);
  std::vector<int> lock2(3);
  for (int i = 0; i < 3; ++i) {
    fin >> lock1[i];
  }
  for (int i = 0; i < 3; ++i) {
    fin >> lock2[i];
  }
  if (N <= 5) {
    fout << N * N * N << endl;
    return 0;
  }
  // tell how many duplicated numbers for each lock digit
  bool duplicate = true;
  std::vector<int> numbers(3);
  for (int i = 0; i < 3; ++i) {
    int a = lock1[i];
    int b = lock2[i];
    int min_a = a - 2;
    int min_b = b - 2;
    int max_a = a + 2;
    int max_b = b + 2;
    if (max_a > N && min_b <= 1) {
      min_b += N;
      max_b += N;
    } else if (max_b > N && min_a <= 1) {
      min_a += N;
      max_a += N;
    }
    bool flag = false;
    if (min_a <= max_b && min_a >= min_b) {
      flag = true;
      numbers[i] = max_b - min_a + 1;
    } else if (min_b >= min_a && min_b <= max_a) {
      flag = true;
      numbers[i] = max_a - min_b + 1;
    }
    duplicate &= flag;
  }
  int duplicated_numbers = 0;
  if (duplicate) {
    duplicated_numbers = numbers[0] * numbers[1] * numbers[2];
  }
  fout << 5*5*5*2 - duplicated_numbers << endl;
  return 0;
}
