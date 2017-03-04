/*
ID: rainywa1
PROG: dualpal
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

std::string converttobase(int number, int base) {
  string num_str;
  while (number > 0) {
    char rest = '0' + number % base;
    num_str += rest;
    number /= base;
  }
  // std::reverse(std::begin(num_str), std::end(num_str));
  return num_str;
}

bool ispalin(string palin) {
  int i = 0;
  int j = palin.length() - 1;
  while (i < j && palin[i] == palin[j]) {
    ++i;
    --j;
  }
  return !(i < j);
}

int main() {
  ofstream fout("dualpal.out");
  ifstream fin("dualpal.in");
  int s, n;
  fin >> s >> n;
  int i = n+1;
  int found = 0;
  while(true) {
    // for each number, for each base, tell palindrome
    int palin_base = 0;
    for (int base = 2; base <= 10; ++base) {
      string palin = converttobase(i, base);
      if (ispalin(palin)) {
        if (++palin_base == 2) {
          ++found;
          fout << i << endl;
          break;
        }
      }
    }
    if (found == s) {
      break;
    }
    ++i;
  }

  /*int i = n + 1;
  for (int found = 0; found < s; ++i) {
    if (HasTwoPalindromeBases(i)) {
      ++found;
      fout << i << endl;
    }
  }*/
  return 0;
}
