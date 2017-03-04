/*
ID: rainywa1
PROG: namenum
LANG: C++11
*/

#include <fstream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int sum(vector<int> &v) {
  int sum = 0;
  for (int i = 0; i < v.size(); ++i) {
    sum += v[i];
  }
  return sum;
}

int main() {
  // process the dict;
  set<string> dict;
  ifstream fin("namenum.in");
  ifstream fdict("dict.txt");
  ofstream fout("namenum.out");
  string name;
  while (fdict >> name) {
    dict.insert(name);
  }

  // construct mapping
  vector<string> mapping({"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"});

  // read digits
  vector<int> digits;
  char digit;
  while (fin >> digit) {
    if (digit == '1' || digit == '0') {
      fout << "NONE" << endl;
      return 0;
    }
    digits.push_back(digit - '0');
  }
  int len = digits.size();
  // counter's index is the index of string.
  vector<int> counter(len, 0);

  string combination(len, ' ');
  bool flag = false;
  while (true) {
    for (int i = 0; i < len; ++i) {
      int digit = digits[i];
      combination[i] = mapping[digit][counter[i]];
    }
    // tell hte combination is in dict or not
    if (dict.count(combination) != 0) {
      fout << combination << endl;
      flag = true;
    }
    // counter + 1
    int index = len - 1;
    ++counter[index];
    while(index > 0 && counter[index] > 2) {
      counter[index] = 0;
      ++counter[index - 1];
      --index;
    }
    if (index == 0 && counter[index] > 2) {
      break;
    }
  }
  if (!flag) {
    fout << "NONE" << endl;;
  }
  return 0;
}
