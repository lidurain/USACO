/*
ID: rainywa1
PROG: palsquare
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
  int org = number;
  while(number > 0) {
    int rest = number % base;
    char symbol;
    if (rest > 9) {
      symbol = 'A' + rest - 10;
    } else {
      symbol = '0' + rest;
    }
    num_str += symbol;
    number = number / base;
  }
  std::reverse(std::begin(num_str), std::end(num_str));
  return num_str;
}

bool ispalin(string palin) {
  int len = palin.length();
  for (int i = 0; i < len/2; ++i) {
    if (palin[i] != palin[len - 1 - i]){
      return false;
    }
  }
  return true;
}

int main() {
  ofstream fout("palsquare.out");
  ifstream fin("palsquare.in");
  int base;
  fin >> base;

  for (int i = 1; i <=300; ++i) {
    int square = i * i;
    string palin = converttobase(square, base);
    if (ispalin(palin)) {
      fout << converttobase(i, base) << " " << palin << endl;
    }
  }
  return 0;
}
