/*
ID: your_id_here
PROG: friday
LANG: C++11
*/

#include <fstream>
#include <vector>

using namespace std;

bool isLeapYear(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  ifstream fin("friday.in");
  ofstream fout("friday.out");

  int years;
  fin >> years;

  std::vector<int> distribute(7);
  std::vector<int> days_per_month({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
  int days = 0;
  for (int year = 1900; year < 1900 + years; ++year) {
    bool leap = isLeapYear(year);
    days_per_month[2] = leap ? 29 : 28;
    int sum = days;
    for (int month = 1; month <= 12; ++month) {
      sum += days_per_month[month - 1];
      distribute[(sum+13) % 7]++;
    }
    days += leap ? 366 : 365;
  }

  int i = 0;
  for (; i < 6; ++i) {
    fout << distribute[(i + 6) % 7] << " ";
  }
  fout << distribute[(i+6) % 7] << endl;
  return 0;
}
