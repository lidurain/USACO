/*
ID: rainywa1
PROG: crypt1
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool DigitsInSet(int product, std::vector<int> &digits) {
  while (product) {
    auto result = std::find(digits.begin(), digits.end(), product % 10);
    if (result == digits.end()) {
      return false;
    }
    product /= 10;
  }
  return true;
}

int main() {
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");

  int n;
  fin >> n;
  if (n == 0) {
    fout << 0 << endl;
    return 0;
  }
  std::vector<int> digits(n);
  for (int i = 0; i < n; ++i) {
    fin >> digits[i];
  }
  std::sort(digits.begin(), digits.end());
  std::vector<int>::iterator it = std::unique(digits.begin(), digits.end());
  digits.resize(std::distance(digits.begin(),it));
  n = digits.size();
  int max = n * n * n * n * n;
  int abc, a, b, c, d, e;
  int solutions = 0;
  for (int i = 0; i < max; ++i) {
    int devided = i;
    std::vector<int> index(5, 0);
    int j = 4;
    while (devided) {
      index[j] = devided % n;
      devided /= n;
      --j;
    }
    a = digits[index[0]];
    b = digits[index[1]];
    c = digits[index[2]];
    abc = 100 * a + 10 * b + c;
    d = digits[index[3]];
    e = digits[index[4]];
    if (abc * e / 100 >= 10 || !DigitsInSet(abc * e, digits)) {
      continue;
    }
    if (abc * d / 100 >= 10 || !DigitsInSet(abc * d, digits)) {
      continue;
    }
    int product = abc * (10 * d + e);
    if (product / 1000 >= 10 || !DigitsInSet(product, digits)) {
      continue;
    }
    ++solutions;
  }
  fout << solutions << endl;
  return 0;
}
