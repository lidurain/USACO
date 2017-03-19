/*
ID: rainywa1
PROG: crypt1
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// template<class Iterator, class Predicate>
// bool for_all(Iterator begin, Iterator end, Predicate pred) {
//   for (Iterator i = begin; i != end; ++i) {
//     if (!pred(*i)) {
//       return false;
//     }
//   }
//   return true;
// }
//
// if (comparator(a, b)) {
// }
//
// Point origin = ..;
// sort(points.begin(), points.end(), [&origin](const Point& a, const Point& b) { return IsClockwise(a - origin, b - origin); });
//
//
// class Functor {
//  public:
//   Functor(Point& origin) {
//     this->origin_ = origin;
//   }
//   bool Foo(const Point& a, const Point b) {
//   bool operator()(const Point& a, const Point& b){
//     return IsClockwise(....);
//   }
//
//  private:
//   Point origin_;
// };

bool DigitsInSet(int num, const std::vector<int> &allowed) {
  std::vector<int> digits;
  while (num > 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  return std::all_of(digits.begin(), digits.end(), [&allowed](int x) {
    return std::binary_search(allowed.begin(), allowed.end(), x);
  });
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
  digits.erase(std::unique(digits.begin(), digits.end()), digits.end());
  n = digits.size();
  int max = n * n * n * n * n;
  int solutions = 0;
  for (int i = 0; i < max; ++i) {
    int dividend = i;
    std::vector<int> index(5, 0);
    for (int j = 0; j < 5; ++j) {
      index[j] = dividend % n;
      dividend /= n;
    }
    int a = digits[index[0]];
    int b = digits[index[1]];
    int c = digits[index[2]];
    int abc = 100 * a + 10 * b + c;
    int d = digits[index[3]];
    int e = digits[index[4]];
    if (abc * e >= 1000 || !DigitsInSet(abc * e, digits)) {
      continue;
    }
    if (abc * d >= 1000 || !DigitsInSet(abc * d, digits)) {
      continue;
    }
    int product = abc * (10 * d + e);
    if (product >= 10000 || !DigitsInSet(product, digits)) {
      continue;
    }
    ++solutions;
  }
  fout << solutions << endl;
  return 0;
}
